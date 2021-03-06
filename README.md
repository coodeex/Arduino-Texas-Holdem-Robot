<h1 align="center">Automatisoitu kortinjakaja</h1>
<br>

Robotin tehtävä on jakaa kortit pelaajille ja pöytään kuten Texas hold'em pokerissa.
<br>
Se on ryhmätyönä suunniteltu, mallinnettu ja rakennettu kokonaan itse eli niin sanotusti from scratch.

## Komponentit

* Arduino UNO
* Askelmoottori 28BYJ-48
* ULN2003 driver board
* 2x Standard Size Servo 
* Pelikortit
* Akselitanko Servolle 
* Akryyliset laserleikatut osat 
* Kulmarautoja
* Nappula
* Nippuside ja sinitarraa korttien linkomista varten
* Muut osat kuten johdot, ruuvit ja mutterit yms.
* 3D-tulostetut osat 

<img alt="3d-printed parts" src="images/fusion360Models.png">

![dealing-cards-1](gifs/deal1.gif)
![dealing-cards-2](gifs/deal2.gif)

## Toimintatavoite

-Robotti jakaa ensin eri puolilla pöytää oleville pelaajille 2 korttia kuvapuoli alaspäin

-Odottaa napin painamista

-Jakaa pöytään 3 korttia vierekkäin kuvapuoli ylöspäin

-Odottaa napin painamista

-Jakaa pöytään 1 kortin kuvapuoli ylöspäin

-Odottaa napin painamista

-Jakaa pöytään 1 kortin kuvapuoli ylöspäin



## Toimintaperiaate 

-Stepper pyörittää linkoa, joka lähettää kortin eteenpäin. 

-Alusta pyörii servon varassa liikkuen seuraavaa pelaajaa kohti.

-Toinen servo voi pyörittää korttipakkakoteloa ylösalaisin.
