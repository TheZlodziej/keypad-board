SamacSys ECAD Model
16254546/937036/2.50/18/3/Integrated Circuit

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r180_80"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.800) (shapeHeight 1.800))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r180_70"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.700) (shapeHeight 1.800))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "MAXM10S00B" (originalName "MAXM10S00B")
		(multiLayer
			(pad (padNum 1) (padStyleRef r180_70) (pt 4.750, -4.400) (rotation 90))
			(pad (padNum 2) (padStyleRef r180_80) (pt 4.750, -3.300) (rotation 90))
			(pad (padNum 3) (padStyleRef r180_80) (pt 4.750, -2.200) (rotation 90))
			(pad (padNum 4) (padStyleRef r180_80) (pt 4.750, -1.100) (rotation 90))
			(pad (padNum 5) (padStyleRef r180_80) (pt 4.750, 0.000) (rotation 90))
			(pad (padNum 6) (padStyleRef r180_80) (pt 4.750, 1.100) (rotation 90))
			(pad (padNum 7) (padStyleRef r180_80) (pt 4.750, 2.200) (rotation 90))
			(pad (padNum 8) (padStyleRef r180_80) (pt 4.750, 3.300) (rotation 90))
			(pad (padNum 9) (padStyleRef r180_70) (pt 4.750, 4.400) (rotation 90))
			(pad (padNum 10) (padStyleRef r180_70) (pt -4.750, 4.400) (rotation 90))
			(pad (padNum 11) (padStyleRef r180_80) (pt -4.750, 3.300) (rotation 90))
			(pad (padNum 12) (padStyleRef r180_80) (pt -4.750, 2.200) (rotation 90))
			(pad (padNum 13) (padStyleRef r180_80) (pt -4.750, 1.100) (rotation 90))
			(pad (padNum 14) (padStyleRef r180_80) (pt -4.750, 0.000) (rotation 90))
			(pad (padNum 15) (padStyleRef r180_80) (pt -4.750, -1.100) (rotation 90))
			(pad (padNum 16) (padStyleRef r180_80) (pt -4.750, -2.200) (rotation 90))
			(pad (padNum 17) (padStyleRef r180_80) (pt -4.750, -3.300) (rotation 90))
			(pad (padNum 18) (padStyleRef r180_70) (pt -4.750, -4.400) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.000) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt 4.85 -5.05) (pt -4.85 -5.05) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -4.85 -5.05) (pt -4.85 5.05) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -4.85 5.05) (pt 4.85 5.05) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 4.85 5.05) (pt 4.85 -5.05) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 6.65 -6.05) (pt -6.65 -6.05) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -6.65 -6.05) (pt -6.65 6.05) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -6.65 6.05) (pt 6.65 6.05) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 6.65 6.05) (pt 6.65 -6.05) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 6.2 -4.4) (pt 6.2 -4.4) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt 6.15, -4.4) (radius 0.05) (startAngle .0) (sweepAngle 180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 6.1 -4.4) (pt 6.1 -4.4) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt 6.15, -4.4) (radius 0.05) (startAngle 180.0) (sweepAngle 180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 4.8 -5.05) (pt -4.8 -5.05) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 4.8 5.05) (pt -4.8 5.05) (width 0.2))
		)
	)
	(symbolDef "MAX-M10S-00B" (originalName "MAX-M10S-00B")

		(pin (pinNum 1) (pt 1700 mils -800 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -825 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 1700 mils -700 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -725 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 1700 mils -600 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -625 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 4) (pt 1700 mils -500 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -525 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 5) (pt 1700 mils -400 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -425 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 6) (pt 1700 mils -300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -325 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 7) (pt 1700 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 8) (pt 1700 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 9) (pt 1700 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1470 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 10) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 11) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 12) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 13) (pt 0 mils -300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -325 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 14) (pt 0 mils -400 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -425 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 15) (pt 0 mils -500 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -525 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 16) (pt 0 mils -600 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -625 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 17) (pt 0 mils -700 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -725 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 18) (pt 0 mils -800 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -825 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 1500 mils 100 mils) (width 6 mils))
		(line (pt 1500 mils 100 mils) (pt 1500 mils -900 mils) (width 6 mils))
		(line (pt 1500 mils -900 mils) (pt 200 mils -900 mils) (width 6 mils))
		(line (pt 200 mils -900 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1550 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "MAX-M10S-00B" (originalName "MAX-M10S-00B") (compHeader (numPins 18) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "GND_1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "TXD") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "RXD") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "4" (pinName "TIMEPULSE") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "5" (pinName "EXTINT") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "6" (pinName "V_BCKP") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "7" (pinName "V_IO") (partNum 1) (symPinNum 7) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "8" (pinName "VCC") (partNum 1) (symPinNum 8) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "9" (pinName "RESET_N") (partNum 1) (symPinNum 9) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "10" (pinName "GND_2") (partNum 1) (symPinNum 10) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "11" (pinName "RF_IN") (partNum 1) (symPinNum 11) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "12" (pinName "GND_3") (partNum 1) (symPinNum 12) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "13" (pinName "LNA_EN") (partNum 1) (symPinNum 13) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "14" (pinName "VCC_RF") (partNum 1) (symPinNum 14) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "15" (pinName "RESERVED") (partNum 1) (symPinNum 15) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "16" (pinName "SDA") (partNum 1) (symPinNum 16) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "17" (pinName "SCL") (partNum 1) (symPinNum 17) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "18" (pinName "SAFEBOOT_N") (partNum 1) (symPinNum 18) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "MAX-M10S-00B"))
		(attachedPattern (patternNum 1) (patternName "MAXM10S00B")
			(numPads 18)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
				(padNum 7) (compPinRef "7")
				(padNum 8) (compPinRef "8")
				(padNum 9) (compPinRef "9")
				(padNum 10) (compPinRef "10")
				(padNum 11) (compPinRef "11")
				(padNum 12) (compPinRef "12")
				(padNum 13) (compPinRef "13")
				(padNum 14) (compPinRef "14")
				(padNum 15) (compPinRef "15")
				(padNum 16) (compPinRef "16")
				(padNum 17) (compPinRef "17")
				(padNum 18) (compPinRef "18")
			)
		)
		(attr "Mouser Part Number" "377-MAX-M10S-00B")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/u-blox/MAX-M10S-00B?qs=A6eO%252BMLsxmT0PfQYPb7LLQ%3D%3D")
		(attr "Manufacturer_Name" "U-Blox")
		(attr "Manufacturer_Part_Number" "MAX-M10S-00B")
		(attr "Description" "GPS Modules u-blox M10 GNSS LCC module, firmware in ROM, SAW filter, LNA")
		(attr "Datasheet Link" "https://content.u-blox.com/sites/default/files/MAX-M10S_IntegrationManual_UBX-20053088.pdf")
		(attr "Height" "2.7 mm")
	)

)
