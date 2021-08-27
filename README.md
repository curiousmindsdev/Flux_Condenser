# Flux Condenser Rev.3

### What is it?

A tiny (35mm x 25mm) PCB badge featuring 24 LEDs that animate to create the “fluxxing” effect. It’s 100% decorative, it doesn’t actually let you travel through time when worn around the neck.

It is controlled by a Microchip ATtiny816 microcontroller. Thankfully this board has a much lower power requirement than the silkscreen indicates on the back, and skips along, sipping power from the single CR2032/LIR2032 coin cell battery (instead of plutonium or a lightning strike), slipped into the rear mounted coin cell holder.

https://user-images.githubusercontent.com/56890227/131141057-b0eb6197-e710-4d84-89a1-9ab057af56d6.mov

https://user-images.githubusercontent.com/56890227/131141300-c1670cdc-f619-4a5a-8890-5401563677f6.mov

### What is changed from Rev.2 to Rev.3?

Thanks to Microchip’s latest ATtiny816 microcontroller now I can dim the LEDs with 8 individual PWM pins. Users can now change the animation type, animation speed, and LED brightness. There are 2 animation types (multi beam and single beam), 2 animation speeds (slow and fast), 4 LED brightness levels (100%, 75%, 50% and 25%).  Power consumption is drastically lowered. At full brightness it draws 2.3mA and at 25% brightness it draws 1.1mA of current from the battery. Also front of the Flux Condenser is now much cleaner. Most of the via drill holes are gone.

### How long will the battery last?

CR2032 (Non-Rechargeable) with average of 210mAh battery capacity.
-	100% LED Brightness :   91 Hours
-	25% LED Brightness	 :   190 Hours

LIR2032 (Rechargeable) with average of 40mAh battery capacity.
-	100% LED Brightness :   17 Hours
-	25% LED Brightness	 :   36 Hours

### Configuration 

To set your desired animation, speed and LED brightness, you have to start flux condenser with configuration interface. In order to do that, you have to turn off your flux condenser. While holding the “Start” button on the back turn the flux condenser on. Now you should see configuration interface. Some of the LEDs should be on and some off according to your configuration. LEDs on each row of all columns, starting from outer to inner are paralleled.  
![LED Numbers](/Photo/FC_Rev.png)
Each LED number from photo shown above represents different setting.

- LED1 : Single Beam Animation
- LED2 : Multi Beam Animation
- LED3 : Slow Animation Speed
- LED4 : Fast Animation Speed
- LED5 : 100% LED Brightness
- LED6 : 75% LED Brightness
- LED7 : 50% LED Brightness
- LED8 : 25% LED Brightness

To choose your preference just hold the start button. All the LEDs should turn off and after a second starting from LED1 each individual LED gets lit. Hold the start until the LED that represents your preferred setting is lit, then release the button. Now your new configuration is set. To see it in more detail check out the video below.

https://www.youtube.com/watch?v=2X2gqoI-mSA

![Multi Beam](/Photo/FC_Rev.3_Front_mBeam.jpg)
![Single Beam](/Photo/FC_Rev.3_Front_sBeam.jpg)
![Front](/Photo/FC_Rev.3_Front.jpg)
![Back](/Photo/FC_Rev.3_Back.jpg)

<a href="https://www.tindie.com/stores/curiousmindsdev/?ref=offsite_badges&utm_source=sellers_Hojadurdy&utm_medium=badges&utm_campaign=badge_large"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104"></a>

[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/O4O512Z0W)
