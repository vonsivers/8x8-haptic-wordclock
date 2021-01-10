import sys, os
import shutil
import math
import itertools
from copy import deepcopy

#              0        1          2      3      4        5    6
LIST_elmt = ["  ("," (start ",") (end ",") "," (layer ",") ","))"]
#LIST_elmt = ["  (gr_line (start 131.571908 182.314571) (end 112.874456 120.68499) (angle 90) (layer Dwgs.User) (width 0.1))"]
#LIST_elmt = ["  (segment (start 118.7 106.7) (end 119.4 106.7) (width 0.25) (layer B.Cu) (net 0))"]
DICT_elmt = {"seg" : ["segment", "(width ", "(net "],
             "arc" : ["gr_arc", "(angle ", "(width "],
             "lne" : ["gr_line", "(angle ", "(width "],
             }
DICT_lyr = { "dwg" : "Dwgs.User",
             "cmt" : "Cmts.User",
             "cut" : "Edge.Cuts",
             "fcu" : "F.Cu",
             "bcu" : "B.Cu",
             "in1" : "In1.Cu",
             "in2" : "In2.Cu"
             }

def FNC_string (element,
                STR_start, #1
                STR_end, #2
                Angle, #4
                layer, #5
                width,
                ):
    STR_line = ""
    """
                      0          1         2    3          4           5
    LIST_elmt = ["  ("," (start ",") (end ",") "," (layer ",") (width ","))"]
    """
    for i in range(len(LIST_elmt)):
        STR_line += LIST_elmt[i]
        if i == 0:
            STR_line += DICT_elmt[element][0]
        if i == 1:
            STR_line += STR_start
        if i == 2:
            STR_line += STR_end
        if i == 3:
            if element == "seg":
                STR_line += DICT_elmt[element][1]
                STR_angle = "{:.3f}".format(width)
            else:
                STR_line += DICT_elmt[element][1]
                if element == "lne":
                    STR_angle = "90"
                else:
                    STR_angle = str(Angle)
            STR_line += STR_angle + ")"
        if i == 4:
            STR_line += DICT_lyr[layer]
        if i == 5:
            if element == "seg":
                STR_line += DICT_elmt[element][2]
                STR_line += str(Angle)
            else:
                STR_line += DICT_elmt[element][2]
                STR_line += "{:.3f}".format(width)
    STR_line += "\n"
    return STR_line

def FNC_polygon (element,
                STR_start, #1
                STR_end, #2
                Angle, #4
                layer, #5
                width,
                ):
    STR_line = ""
    """
                      0          1         2    3          4           5
    LIST_elmt = ["  ("," (start ",") (end ",") "," (layer ",") (width ","))"]
    """
    for i in range(len(LIST_elmt)):
        STR_line += LIST_elmt[i]
        if i == 0:
            STR_line += DICT_elmt[element][0]
        if i == 1:
            STR_line += STR_start
        if i == 2:
            STR_line += STR_end
        if i == 3:
            if element == "seg":
                STR_line += DICT_elmt[element][1]
                STR_angle = "{:.3f}".format(width)
            else:
                STR_line += DICT_elmt[element][1]
                if element == "lne":
                    STR_angle = "90"
                else:
                    STR_angle = str(Angle)
            STR_line += STR_angle + ")"
        if i == 4:
            STR_line += DICT_lyr[layer]
        if i == 5:
            if element == "seg":
                STR_line += DICT_elmt[element][2]
                STR_line += str(Angle)
            else:
                STR_line += DICT_elmt[element][2]
                STR_line += "{:.3f}".format(width)
    STR_line += "\n"
    return STR_line


def FNC_spiral (cntr, # (x,y)
                radius,
                segs,
                startangle,
                tw, # track width
                td, # track distance
                turns,
                spin, # cw or ccw, +1 or -1
                layer,
                net,
                ):

    STR_data = ""
    baseX = cntr[0]
    baseY = cntr[1]

    for j in range(turns):

        segs += 4.0
        segangle = 360.0 / segs
        segradius = td / segs

        for i in range(int(segs)):
            # central rings for HV and SNS
            startX = baseX + (radius + segradius * i + td * (j+1)) * math.sin(math.radians(segangle*spin*i + startangle))
            startY = baseY + (radius + segradius * i + td * (j+1)) * math.cos(math.radians(segangle*spin*i + startangle))
            endX = baseX + (radius + segradius * (i + 1.0) + td * (j+1)) * math.sin(math.radians(segangle*spin*(i + 1.0) + startangle))
            endY = baseY + (radius + segradius * (i + 1.0) + td * (j+1)) * math.cos(math.radians(segangle*spin*(i + 1.0) + startangle))
            STR_data += FNC_string ("seg", #type of line
                                    "{:.6f}".format(startX) + " " + "{:.6f}".format(startY), # start point
                                    "{:.6f}".format(endX) + " " + "{:.6f}".format(endY), # end point
                                    net, # angle or net value
                                    layer, # layer on pcb
                                    tw, # track width
                                    )
    return STR_data


if __name__ == '__main__':

    f = open("C:/Users/Moritz/Documents/DIY Projects/haptic display/PCBs/haptic display/haptic display 8x8 aisler/pcbcoils.txt", "w")

    centerX = 50   # x/y coordinates of the centre of first coil (mm)
    centerY = 50

    #a_med = 2.0     # mean radius of coil (mm)
    Radius = 1.2    # start radius in mm
    s = 0.1         # track distance (mm)
    w = 0.15        # track width (mm)
    N = 12           # number of turns per layer
    NLayers = 4     # number of layers (2 or 4)

    pitch = 15      # coil pitch (mm)
    nrows = 8      # number of rows
    ncols = 8      # number of columns

    alternate = True    # alternating spin of coils

    da = (N-1)*s+N*w    # width of coil
    #Radius = a_med - da/2 - (w+s) # start radius in mm
    Sides = 40.0
    StartAngle = 0.0 # degrees
    TrackWidth = w
    TrackDistance = w+s
    Turns = N

    # create coil array
    Spin = 1 # ccw = +1, cw = -1
    for row in range(nrows):
        yc = row*pitch
        if (ncols % 2) == 0:
            Spin = -Spin    # rows should start with alternating spin
        for col in range(ncols):
            xc = col*pitch
            Center = [centerX+xc,centerY+yc]  # x/y coordinates of the centre
            Net = "{}".format(col+1)   # all rows on same net

            # front layer
            Layer = "fcu"
            f.write(FNC_spiral(Center, Radius, Sides, StartAngle, TrackWidth, TrackDistance, Turns, Spin, Layer, Net))  

            if NLayers == 4: 
                Layer = "in1"
                f.write(FNC_spiral(Center, Radius, Sides, StartAngle, TrackWidth, TrackDistance, Turns, -Spin, Layer, Net))
                Layer = "in2"
                f.write(FNC_spiral(Center, Radius, Sides, StartAngle, TrackWidth, TrackDistance, Turns, Spin, Layer, Net))

            # back layer
            Layer = "bcu"
            f.write(FNC_spiral(Center, Radius, Sides, StartAngle, TrackWidth, TrackDistance, Turns, -Spin, Layer, Net))

            if alternate:
                Spin = -Spin 

    f.close()
    print("data successfully written to file!")