EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev "1"
Comp ""
Comment1 "Designed for AISLER 2-Layer Service"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:WeMos_D1_mini U1
U 1 1 5FF90183
P 1850 4150
F 0 "U1" H 1850 3261 50  0000 C CNN
F 1 "WeMos_D1_mini" H 1850 3170 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 1850 3000 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 0   3000 50  0001 C CNN
	1    1850 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J2
U 1 1 5FF9205D
P 7950 1900
F 0 "J2" H 7978 1876 50  0000 L CNN
F 1 "Conn_01x08_Female" H 7978 1785 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 7950 1900 50  0001 C CNN
F 3 "~" H 7950 1900 50  0001 C CNN
	1    7950 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J3
U 1 1 5FF93991
P 7950 2850
F 0 "J3" H 7978 2826 50  0000 L CNN
F 1 "Conn_01x08_Female" H 7978 2735 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 7950 2850 50  0001 C CNN
F 3 "~" H 7950 2850 50  0001 C CNN
	1    7950 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5FFA857B
P 4350 950
F 0 "#PWR014" H 4350 700 50  0001 C CNN
F 1 "GND" V 4355 822 50  0000 R CNN
F 2 "" H 4350 950 50  0001 C CNN
F 3 "" H 4350 950 50  0001 C CNN
	1    4350 950 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5FFA8F17
P 5750 950
F 0 "#PWR017" H 5750 700 50  0001 C CNN
F 1 "GND" V 5755 822 50  0000 R CNN
F 2 "" H 5750 950 50  0001 C CNN
F 3 "" H 5750 950 50  0001 C CNN
	1    5750 950 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5FFA979D
P 5750 2050
F 0 "#PWR018" H 5750 1800 50  0001 C CNN
F 1 "GND" V 5755 1922 50  0000 R CNN
F 2 "" H 5750 2050 50  0001 C CNN
F 3 "" H 5750 2050 50  0001 C CNN
	1    5750 2050
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR032
U 1 1 5FFABA70
P 6400 1250
F 0 "#PWR032" H 6400 1100 50  0001 C CNN
F 1 "+5V" V 6415 1378 50  0000 L CNN
F 2 "" H 6400 1250 50  0001 C CNN
F 3 "" H 6400 1250 50  0001 C CNN
	1    6400 1250
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5FFAEB5C
P 2350 3200
F 0 "C1" H 2465 3246 50  0000 L CNN
F 1 "1µF" H 2465 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2388 3050 50  0001 C CNN
F 3 "~" H 2350 3200 50  0001 C CNN
	1    2350 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C4
U 1 1 5FFAF844
P 3650 1600
F 0 "C4" H 3765 1646 50  0000 L CNN
F 1 "0.1µF" H 3765 1555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3688 1450 50  0001 C CNN
F 3 "~" H 3650 1600 50  0001 C CNN
	1    3650 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5FFAFDB1
P 3650 1750
F 0 "#PWR011" H 3650 1500 50  0001 C CNN
F 1 "GND" H 3655 1577 50  0000 C CNN
F 2 "" H 3650 1750 50  0001 C CNN
F 3 "" H 3650 1750 50  0001 C CNN
	1    3650 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5FFB01CE
P 2350 3350
F 0 "#PWR08" H 2350 3100 50  0001 C CNN
F 1 "GND" H 2355 3177 50  0000 C CNN
F 2 "" H 2350 3350 50  0001 C CNN
F 3 "" H 2350 3350 50  0001 C CNN
	1    2350 3350
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:DRV8912QPWPRQ1 IC1
U 1 1 5FF8E5CE
P 4350 950
F 0 "IC1" H 5050 1215 50  0000 C CNN
F 1 "DRV8912QPWPRQ1" H 5050 1124 50  0000 C CNN
F 2 "SamacSys_Parts:SOP65P640X120-25N" H 5600 1050 50  0001 L CNN
F 3 "https://www.ti.com/lit/gpn/DRV8912-Q1" H 5600 950 50  0001 L CNN
F 4 "Motor / Motion / Ignition Controllers & Drivers Automotive 12 channel half bridge motor driver 24-HTSSOP -40 to 125" H 5600 850 50  0001 L CNN "Description"
F 5 "1.2" H 5600 750 50  0001 L CNN "Height"
F 6 "595-DRV8912QPWPRQ1" H 5600 650 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/DRV8912QPWPRQ1/?qs=xZ%2FP%252Ba9zWqY%252Bu79cpqW%2Fvw%3D%3D" H 5600 550 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 5600 450 50  0001 L CNN "Manufacturer_Name"
F 9 "DRV8912QPWPRQ1" H 5600 350 50  0001 L CNN "Manufacturer_Part_Number"
	1    4350 950 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR05
U 1 1 5FFB50DB
P 3650 1450
F 0 "#PWR05" H 3650 1300 50  0001 C CNN
F 1 "+3.3V" V 3665 1578 50  0000 L CNN
F 2 "" H 3650 1450 50  0001 C CNN
F 3 "" H 3650 1450 50  0001 C CNN
	1    3650 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5FFB5DAD
P 6100 1400
F 0 "C7" H 6215 1446 50  0000 L CNN
F 1 "0.1µF" H 6215 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 1250 50  0001 C CNN
F 3 "~" H 6100 1400 50  0001 C CNN
	1    6100 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5FFB652D
P 950 2550
F 0 "C13" H 1065 2596 50  0000 L CNN
F 1 "10µF" H 1065 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 988 2400 50  0001 C CNN
F 3 "~" H 950 2550 50  0001 C CNN
	1    950  2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5FFB75DC
P 6100 1900
F 0 "C8" H 6215 1946 50  0000 L CNN
F 1 "0.1µF" H 6215 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 1750 50  0001 C CNN
F 3 "~" H 6100 1900 50  0001 C CNN
	1    6100 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5FFB7E53
P 6100 1550
F 0 "#PWR023" H 6100 1300 50  0001 C CNN
F 1 "GND" H 6105 1377 50  0000 C CNN
F 2 "" H 6100 1550 50  0001 C CNN
F 3 "" H 6100 1550 50  0001 C CNN
	1    6100 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5FFB815C
P 950 2700
F 0 "#PWR029" H 950 2450 50  0001 C CNN
F 1 "GND" H 955 2527 50  0000 C CNN
F 2 "" H 950 2700 50  0001 C CNN
F 3 "" H 950 2700 50  0001 C CNN
	1    950  2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5FFB84F7
P 6100 2050
F 0 "#PWR024" H 6100 1800 50  0001 C CNN
F 1 "GND" H 6105 1877 50  0000 C CNN
F 2 "" H 6100 2050 50  0001 C CNN
F 3 "" H 6100 2050 50  0001 C CNN
	1    6100 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 1250 6400 1250
Wire Wire Line
	6400 1750 6400 1250
Wire Wire Line
	6100 1750 6400 1750
Text GLabel 4350 1350 0    50   Input ~ 0
MOSI
Text GLabel 4350 1550 0    50   Input ~ 0
MISO
Text GLabel 5750 1350 2    50   Input ~ 0
SCK
Text GLabel 4350 1650 0    50   Input ~ 0
ENABLE
Text GLabel 2250 4450 2    50   Input ~ 0
MOSI
Text GLabel 2250 4350 2    50   Input ~ 0
MISO
Text GLabel 2250 4250 2    50   Input ~ 0
SCK
Text GLabel 5750 1450 2    50   Input ~ 0
CS1
Text GLabel 2250 4550 2    50   Input ~ 0
CS1
Text GLabel 2250 4150 2    50   Input ~ 0
CS2
Text GLabel 2250 4050 2    50   Input ~ 0
CS3
Text GLabel 2250 3950 2    50   Input ~ 0
ENABLE
Wire Wire Line
	3650 1450 4350 1450
Wire Wire Line
	5750 1250 6100 1250
Connection ~ 6100 1250
Wire Wire Line
	5750 1750 6100 1750
Connection ~ 6100 1750
$Comp
L power:+3.3V #PWR04
U 1 1 5FFBF5A1
P 1950 3050
F 0 "#PWR04" H 1950 2900 50  0001 C CNN
F 1 "+3.3V" H 1965 3223 50  0000 C CNN
F 2 "" H 1950 3050 50  0001 C CNN
F 3 "" H 1950 3050 50  0001 C CNN
	1    1950 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5FFBFBB2
P 1750 3350
F 0 "#PWR03" H 1750 3200 50  0001 C CNN
F 1 "+5V" H 1765 3523 50  0000 C CNN
F 2 "" H 1750 3350 50  0001 C CNN
F 3 "" H 1750 3350 50  0001 C CNN
	1    1750 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FFC4BFE
P 4350 3100
F 0 "#PWR015" H 4350 2850 50  0001 C CNN
F 1 "GND" V 4355 2972 50  0000 R CNN
F 2 "" H 4350 3100 50  0001 C CNN
F 3 "" H 4350 3100 50  0001 C CNN
	1    4350 3100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5FFC4C08
P 5750 3100
F 0 "#PWR019" H 5750 2850 50  0001 C CNN
F 1 "GND" V 5755 2972 50  0000 R CNN
F 2 "" H 5750 3100 50  0001 C CNN
F 3 "" H 5750 3100 50  0001 C CNN
	1    5750 3100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5FFC4C12
P 5750 4200
F 0 "#PWR020" H 5750 3950 50  0001 C CNN
F 1 "GND" V 5755 4072 50  0000 R CNN
F 2 "" H 5750 4200 50  0001 C CNN
F 3 "" H 5750 4200 50  0001 C CNN
	1    5750 4200
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR033
U 1 1 5FFC4C1C
P 6400 3400
F 0 "#PWR033" H 6400 3250 50  0001 C CNN
F 1 "+5V" V 6415 3528 50  0000 L CNN
F 2 "" H 6400 3400 50  0001 C CNN
F 3 "" H 6400 3400 50  0001 C CNN
	1    6400 3400
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5FFC4C31
P 3650 3750
F 0 "C5" H 3765 3796 50  0000 L CNN
F 1 "0.1µF" H 3765 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3688 3600 50  0001 C CNN
F 3 "~" H 3650 3750 50  0001 C CNN
	1    3650 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5FFC4C3B
P 3650 3900
F 0 "#PWR012" H 3650 3650 50  0001 C CNN
F 1 "GND" H 3655 3727 50  0000 C CNN
F 2 "" H 3650 3900 50  0001 C CNN
F 3 "" H 3650 3900 50  0001 C CNN
	1    3650 3900
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:DRV8912QPWPRQ1 IC2
U 1 1 5FFC4C56
P 4350 3100
F 0 "IC2" H 5050 3365 50  0000 C CNN
F 1 "DRV8912QPWPRQ1" H 5050 3274 50  0000 C CNN
F 2 "SamacSys_Parts:SOP65P640X120-25N" H 5600 3200 50  0001 L CNN
F 3 "https://www.ti.com/lit/gpn/DRV8912-Q1" H 5600 3100 50  0001 L CNN
F 4 "Motor / Motion / Ignition Controllers & Drivers Automotive 12 channel half bridge motor driver 24-HTSSOP -40 to 125" H 5600 3000 50  0001 L CNN "Description"
F 5 "1.2" H 5600 2900 50  0001 L CNN "Height"
F 6 "595-DRV8912QPWPRQ1" H 5600 2800 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/DRV8912QPWPRQ1/?qs=xZ%2FP%252Ba9zWqY%252Bu79cpqW%2Fvw%3D%3D" H 5600 2700 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 5600 2600 50  0001 L CNN "Manufacturer_Name"
F 9 "DRV8912QPWPRQ1" H 5600 2500 50  0001 L CNN "Manufacturer_Part_Number"
	1    4350 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR06
U 1 1 5FFC4C61
P 3650 3600
F 0 "#PWR06" H 3650 3450 50  0001 C CNN
F 1 "+3.3V" V 3665 3728 50  0000 L CNN
F 2 "" H 3650 3600 50  0001 C CNN
F 3 "" H 3650 3600 50  0001 C CNN
	1    3650 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5FFC4C6C
P 6100 3550
F 0 "C9" H 6215 3596 50  0000 L CNN
F 1 "0.1µF" H 6215 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 3400 50  0001 C CNN
F 3 "~" H 6100 3550 50  0001 C CNN
	1    6100 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5FFC4C80
P 6100 4050
F 0 "C10" H 6215 4096 50  0000 L CNN
F 1 "0.1µF" H 6215 4005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 3900 50  0001 C CNN
F 3 "~" H 6100 4050 50  0001 C CNN
	1    6100 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5FFC4C8A
P 6100 3700
F 0 "#PWR025" H 6100 3450 50  0001 C CNN
F 1 "GND" H 6105 3527 50  0000 C CNN
F 2 "" H 6100 3700 50  0001 C CNN
F 3 "" H 6100 3700 50  0001 C CNN
	1    6100 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5FFC4C9E
P 6100 4200
F 0 "#PWR026" H 6100 3950 50  0001 C CNN
F 1 "GND" H 6105 4027 50  0000 C CNN
F 2 "" H 6100 4200 50  0001 C CNN
F 3 "" H 6100 4200 50  0001 C CNN
	1    6100 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3400 6400 3400
Wire Wire Line
	6400 3900 6400 3400
Wire Wire Line
	6100 3900 6400 3900
Text GLabel 4350 3500 0    50   Input ~ 0
MOSI
Text GLabel 4350 3700 0    50   Input ~ 0
MISO
Text GLabel 5750 3500 2    50   Input ~ 0
SCK
Text GLabel 4350 3800 0    50   Input ~ 0
ENABLE
Text GLabel 5750 3600 2    50   Input ~ 0
CS2
Wire Wire Line
	3650 3600 4350 3600
Wire Wire Line
	5750 3400 6100 3400
Connection ~ 6100 3400
Wire Wire Line
	5750 3900 6100 3900
Connection ~ 6100 3900
$Comp
L power:GND #PWR016
U 1 1 5FFC910D
P 4350 5300
F 0 "#PWR016" H 4350 5050 50  0001 C CNN
F 1 "GND" V 4355 5172 50  0000 R CNN
F 2 "" H 4350 5300 50  0001 C CNN
F 3 "" H 4350 5300 50  0001 C CNN
	1    4350 5300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5FFC9117
P 5750 5300
F 0 "#PWR021" H 5750 5050 50  0001 C CNN
F 1 "GND" V 5755 5172 50  0000 R CNN
F 2 "" H 5750 5300 50  0001 C CNN
F 3 "" H 5750 5300 50  0001 C CNN
	1    5750 5300
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5FFC9121
P 5750 6400
F 0 "#PWR022" H 5750 6150 50  0001 C CNN
F 1 "GND" V 5755 6272 50  0000 R CNN
F 2 "" H 5750 6400 50  0001 C CNN
F 3 "" H 5750 6400 50  0001 C CNN
	1    5750 6400
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR034
U 1 1 5FFC912B
P 6400 5600
F 0 "#PWR034" H 6400 5450 50  0001 C CNN
F 1 "+5V" V 6415 5728 50  0000 L CNN
F 2 "" H 6400 5600 50  0001 C CNN
F 3 "" H 6400 5600 50  0001 C CNN
	1    6400 5600
	0    1    1    0   
$EndComp
$Comp
L Device:C C6
U 1 1 5FFC9140
P 3650 5950
F 0 "C6" H 3765 5996 50  0000 L CNN
F 1 "0.1µF" H 3765 5905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3688 5800 50  0001 C CNN
F 3 "~" H 3650 5950 50  0001 C CNN
	1    3650 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FFC914A
P 3650 6100
F 0 "#PWR013" H 3650 5850 50  0001 C CNN
F 1 "GND" H 3655 5927 50  0000 C CNN
F 2 "" H 3650 6100 50  0001 C CNN
F 3 "" H 3650 6100 50  0001 C CNN
	1    3650 6100
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:DRV8912QPWPRQ1 IC3
U 1 1 5FFC9165
P 4350 5300
F 0 "IC3" H 5050 5565 50  0000 C CNN
F 1 "DRV8912QPWPRQ1" H 5050 5474 50  0000 C CNN
F 2 "SamacSys_Parts:SOP65P640X120-25N" H 5600 5400 50  0001 L CNN
F 3 "https://www.ti.com/lit/gpn/DRV8912-Q1" H 5600 5300 50  0001 L CNN
F 4 "Motor / Motion / Ignition Controllers & Drivers Automotive 12 channel half bridge motor driver 24-HTSSOP -40 to 125" H 5600 5200 50  0001 L CNN "Description"
F 5 "1.2" H 5600 5100 50  0001 L CNN "Height"
F 6 "595-DRV8912QPWPRQ1" H 5600 5000 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/DRV8912QPWPRQ1/?qs=xZ%2FP%252Ba9zWqY%252Bu79cpqW%2Fvw%3D%3D" H 5600 4900 50  0001 L CNN "Mouser Price/Stock"
F 8 "Texas Instruments" H 5600 4800 50  0001 L CNN "Manufacturer_Name"
F 9 "DRV8912QPWPRQ1" H 5600 4700 50  0001 L CNN "Manufacturer_Part_Number"
	1    4350 5300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR07
U 1 1 5FFC9170
P 3650 5800
F 0 "#PWR07" H 3650 5650 50  0001 C CNN
F 1 "+3.3V" V 3665 5928 50  0000 L CNN
F 2 "" H 3650 5800 50  0001 C CNN
F 3 "" H 3650 5800 50  0001 C CNN
	1    3650 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5FFC917B
P 6100 5750
F 0 "C11" H 6215 5796 50  0000 L CNN
F 1 "0.1µF" H 6215 5705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 5600 50  0001 C CNN
F 3 "~" H 6100 5750 50  0001 C CNN
	1    6100 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5FFC918F
P 6100 6250
F 0 "C12" H 6215 6296 50  0000 L CNN
F 1 "0.1µF" H 6215 6205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 6100 50  0001 C CNN
F 3 "~" H 6100 6250 50  0001 C CNN
	1    6100 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5FFC9199
P 6100 5900
F 0 "#PWR027" H 6100 5650 50  0001 C CNN
F 1 "GND" H 6105 5727 50  0000 C CNN
F 2 "" H 6100 5900 50  0001 C CNN
F 3 "" H 6100 5900 50  0001 C CNN
	1    6100 5900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 5FFC91AD
P 6100 6400
F 0 "#PWR028" H 6100 6150 50  0001 C CNN
F 1 "GND" H 6105 6227 50  0000 C CNN
F 2 "" H 6100 6400 50  0001 C CNN
F 3 "" H 6100 6400 50  0001 C CNN
	1    6100 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5600 6400 5600
Wire Wire Line
	6400 6100 6400 5600
Wire Wire Line
	6100 6100 6400 6100
Text GLabel 4350 5700 0    50   Input ~ 0
MOSI
Text GLabel 4350 5900 0    50   Input ~ 0
MISO
Text GLabel 5750 5700 2    50   Input ~ 0
SCK
Text GLabel 4350 6000 0    50   Input ~ 0
ENABLE
Text GLabel 5750 5800 2    50   Input ~ 0
CS3
Wire Wire Line
	3650 5800 4350 5800
Wire Wire Line
	5750 5600 6100 5600
Connection ~ 6100 5600
Wire Wire Line
	5750 6100 6100 6100
Connection ~ 6100 6100
Text Label 7500 1600 0    50   ~ 0
r1_f
Text Label 7500 1700 0    50   ~ 0
r2_f
Text Label 7500 1800 0    50   ~ 0
r3_f
Text Label 7500 1900 0    50   ~ 0
r4_f
Text Label 7500 2000 0    50   ~ 0
r5_f
Text Label 7500 2100 0    50   ~ 0
r6_f
Text Label 7500 2200 0    50   ~ 0
r7_f
Text Label 7500 2300 0    50   ~ 0
r8_f
Wire Wire Line
	7500 1600 7750 1600
Wire Wire Line
	7500 1700 7750 1700
Wire Wire Line
	7500 1800 7750 1800
Wire Wire Line
	7500 1900 7750 1900
Wire Wire Line
	7500 2000 7750 2000
Wire Wire Line
	7500 2100 7750 2100
Wire Wire Line
	7500 2200 7750 2200
Wire Wire Line
	7500 2300 7750 2300
Text Label 7500 2550 0    50   ~ 0
c1_f
Text Label 7500 2650 0    50   ~ 0
c2_f
Text Label 7500 2750 0    50   ~ 0
c3_f
Text Label 7500 2850 0    50   ~ 0
c4_f
Text Label 7500 2950 0    50   ~ 0
c5_f
Text Label 7500 3050 0    50   ~ 0
c6_f
Text Label 7500 3150 0    50   ~ 0
c7_f
Text Label 7500 3250 0    50   ~ 0
c8_f
Wire Wire Line
	7500 2550 7750 2550
Wire Wire Line
	7500 2650 7750 2650
Wire Wire Line
	7500 2750 7750 2750
Wire Wire Line
	7500 2850 7750 2850
Wire Wire Line
	7500 2950 7750 2950
Wire Wire Line
	7500 3050 7750 3050
Wire Wire Line
	7500 3150 7750 3150
Wire Wire Line
	7500 3250 7750 3250
$Comp
L Connector:Conn_01x08_Female J4
U 1 1 5FFD8248
P 7950 3750
F 0 "J4" H 7978 3726 50  0000 L CNN
F 1 "Conn_01x08_Female" H 7978 3635 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 7950 3750 50  0001 C CNN
F 3 "~" H 7950 3750 50  0001 C CNN
	1    7950 3750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J5
U 1 1 5FFD8252
P 7950 4700
F 0 "J5" H 7978 4676 50  0000 L CNN
F 1 "Conn_01x08_Female" H 7978 4585 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 7950 4700 50  0001 C CNN
F 3 "~" H 7950 4700 50  0001 C CNN
	1    7950 4700
	1    0    0    -1  
$EndComp
Text Label 7500 3450 0    50   ~ 0
r1_b
Text Label 7500 3550 0    50   ~ 0
r2_b
Text Label 7500 3650 0    50   ~ 0
r3_b
Text Label 7500 3850 0    50   ~ 0
r5_b
Text Label 7500 3950 0    50   ~ 0
r6_b
Text Label 7500 4050 0    50   ~ 0
r7_b
Text Label 7500 4150 0    50   ~ 0
r8_b
Wire Wire Line
	7500 3450 7750 3450
Wire Wire Line
	7500 3550 7750 3550
Wire Wire Line
	7500 3650 7750 3650
Wire Wire Line
	7500 3750 7750 3750
Wire Wire Line
	7500 3850 7750 3850
Wire Wire Line
	7500 3950 7750 3950
Wire Wire Line
	7500 4050 7750 4050
Wire Wire Line
	7500 4150 7750 4150
Text Label 7500 4400 0    50   ~ 0
c1_b
Text Label 7500 4500 0    50   ~ 0
c2_b
Text Label 7500 4600 0    50   ~ 0
c3_b
Text Label 7500 4700 0    50   ~ 0
c4_b
Text Label 7500 4800 0    50   ~ 0
c5_b
Text Label 7500 4900 0    50   ~ 0
c6_b
Text Label 7500 5000 0    50   ~ 0
c7_b
Text Label 7500 5100 0    50   ~ 0
c8_b
Wire Wire Line
	7500 4400 7750 4400
Wire Wire Line
	7500 4500 7750 4500
Wire Wire Line
	7500 4600 7750 4600
Wire Wire Line
	7500 4700 7750 4700
Wire Wire Line
	7500 4800 7750 4800
Wire Wire Line
	7500 4900 7750 4900
Wire Wire Line
	7500 5000 7750 5000
Wire Wire Line
	7500 5100 7750 5100
$Comp
L UJC-HP-3-SMT-TR:UJC-HP-3-SMT-TR J1
U 1 1 5FFDEECC
P 1850 2250
F 0 "J1" H 2180 2246 50  0000 L CNN
F 1 "UJC-HP-3-SMT-TR" H 2180 2155 50  0000 L CNN
F 2 "user-footprints:CUI_UJC-HP-3-SMT-TR" H 1850 2250 50  0001 L BNN
F 3 "" H 1850 2250 50  0001 L BNN
F 4 "CUI Devices" H 1850 2250 50  0001 L BNN "MANUFACTURER"
F 5 "3.16mm" H 1850 2250 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
F 6 "Manufacturer Recommendations" H 1850 2250 50  0001 L BNN "STANDARD"
F 7 "1.0" H 1850 2250 50  0001 L BNN "PARTREV"
	1    1850 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5FFE017C
P 850 2250
F 0 "#PWR01" H 850 2100 50  0001 C CNN
F 1 "+5V" H 865 2423 50  0000 C CNN
F 2 "" H 850 2250 50  0001 C CNN
F 3 "" H 850 2250 50  0001 C CNN
	1    850  2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FFE0A62
P 1350 2350
F 0 "#PWR02" H 1350 2100 50  0001 C CNN
F 1 "GND" H 1355 2177 50  0000 C CNN
F 2 "" H 1350 2350 50  0001 C CNN
F 3 "" H 1350 2350 50  0001 C CNN
	1    1350 2350
	0    1    1    0   
$EndComp
Text Label 4150 1050 0    50   ~ 0
r1_f
Text Label 5850 1050 0    50   ~ 0
r2_f
Text Label 5850 1950 0    50   ~ 0
r3_f
Text Label 4150 1950 0    50   ~ 0
r4_f
Text Label 4150 1150 0    50   ~ 0
r5_f
Text Label 4150 1850 0    50   ~ 0
r6_f
Text Label 4150 1250 0    50   ~ 0
r7_f
Text Label 5850 1150 0    50   ~ 0
r8_f
Wire Wire Line
	5750 1050 5850 1050
Wire Wire Line
	5750 1150 5850 1150
Wire Wire Line
	4150 1050 4350 1050
Wire Wire Line
	4150 1150 4350 1150
Wire Wire Line
	4150 1250 4350 1250
Wire Wire Line
	4150 1850 4350 1850
Wire Wire Line
	4150 1950 4350 1950
Text Label 4150 1750 0    50   ~ 0
c1_f
Text Label 5850 1850 0    50   ~ 0
c2_f
Text Label 5850 1650 0    50   ~ 0
c3_f
Text Label 5850 1550 0    50   ~ 0
c4_f
Wire Wire Line
	5750 1550 5850 1550
Wire Wire Line
	5750 1650 5850 1650
Wire Wire Line
	5750 1850 5850 1850
Wire Wire Line
	5750 1950 5850 1950
Wire Wire Line
	4150 1750 4350 1750
Text Label 4150 3200 0    50   ~ 0
c5_f
Text Label 5850 3200 0    50   ~ 0
c6_f
Text Label 5850 4100 0    50   ~ 0
c7_f
Text Label 4150 4100 0    50   ~ 0
c8_f
Text Label 4150 3300 0    50   ~ 0
r1_b
Text Label 4150 4000 0    50   ~ 0
r2_b
Text Label 7500 3750 0    50   ~ 0
r4_b
Text Label 4150 3400 0    50   ~ 0
r3_b
Text Label 5850 3300 0    50   ~ 0
r4_b
Text Label 4150 3900 0    50   ~ 0
r5_b
Text Label 5850 4000 0    50   ~ 0
r6_b
Text Label 5850 3800 0    50   ~ 0
r7_b
Text Label 5850 3700 0    50   ~ 0
r8_b
Wire Wire Line
	4150 3200 4350 3200
Wire Wire Line
	4150 3300 4350 3300
Wire Wire Line
	4150 3400 4350 3400
Wire Wire Line
	4150 3900 4350 3900
Wire Wire Line
	4150 4000 4350 4000
Wire Wire Line
	4150 4100 4350 4100
Wire Wire Line
	5850 3200 5750 3200
Wire Wire Line
	5850 3300 5750 3300
Wire Wire Line
	5850 3700 5750 3700
Wire Wire Line
	5850 3800 5750 3800
Wire Wire Line
	5850 4000 5750 4000
Wire Wire Line
	5850 4100 5750 4100
Text Label 4150 5400 0    50   ~ 0
c1_b
Text Label 5850 5400 0    50   ~ 0
c2_b
Text Label 5850 6300 0    50   ~ 0
c3_b
Text Label 4150 6300 0    50   ~ 0
c4_b
Text Label 4150 5500 0    50   ~ 0
c5_b
Text Label 4150 6200 0    50   ~ 0
c6_b
Text Label 4150 5600 0    50   ~ 0
c7_b
Text Label 5850 5500 0    50   ~ 0
c8_b
Wire Wire Line
	4150 5400 4350 5400
Wire Wire Line
	4150 5500 4350 5500
Wire Wire Line
	4150 5600 4350 5600
Wire Wire Line
	4150 6200 4350 6200
Wire Wire Line
	4150 6300 4350 6300
Wire Wire Line
	5750 5400 5850 5400
Wire Wire Line
	5750 5500 5850 5500
Wire Wire Line
	5750 6300 5850 6300
Wire Wire Line
	1950 3050 1950 3350
Wire Wire Line
	2350 3050 1950 3050
Connection ~ 1950 3050
Wire Wire Line
	1350 2250 950  2250
Wire Wire Line
	950  2400 950  2250
Connection ~ 950  2250
Wire Wire Line
	950  2250 850  2250
Connection ~ 6400 1250
Connection ~ 6400 3400
Connection ~ 6400 5600
Connection ~ 3650 1450
Connection ~ 3650 3600
Connection ~ 3650 5800
$Comp
L power:GND #PWR?
U 1 1 5FFBA84F
P 5050 6900
F 0 "#PWR?" H 5050 6650 50  0001 C CNN
F 1 "GND" H 5055 6727 50  0000 C CNN
F 2 "" H 5050 6900 50  0001 C CNN
F 3 "" H 5050 6900 50  0001 C CNN
	1    5050 6900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FFBABCD
P 5050 4700
F 0 "#PWR?" H 5050 4450 50  0001 C CNN
F 1 "GND" H 5055 4527 50  0000 C CNN
F 2 "" H 5050 4700 50  0001 C CNN
F 3 "" H 5050 4700 50  0001 C CNN
	1    5050 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FFBAE67
P 5050 2550
F 0 "#PWR?" H 5050 2300 50  0001 C CNN
F 1 "GND" H 5055 2377 50  0000 C CNN
F 2 "" H 5050 2550 50  0001 C CNN
F 3 "" H 5050 2550 50  0001 C CNN
	1    5050 2550
	1    0    0    -1  
$EndComp
$EndSCHEMATC