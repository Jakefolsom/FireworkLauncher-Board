# FireworkLauncher-Board

## What is it?
This is a firework launcher that is completly controlled by a IOS app. The acutal firework launcher is controlled by a ESP32 board. This C code puts out a wifi hotspot that the IOS app will then connect to. The webserver host by the ESP32 board will accept GET requests to trigger relays which will light the firework fuses.
