<h1 align="center">Automatisoitu kortinjakaja</h1>
<br>

Robotin tehtävä on jakaa kortit pelaajille ja pöytään kuten Texas hold'em pokerissa.

## Komponentit

* Arduino UNO
* Askelmoottori 28BYJ-48
* ULN2003 driver board
* 2x Standard Size Servo 
* Pelikortit
* 3D-tulostetut osat 
* Akselitanko Servolle 
* Akryyliset laserleikatut osat 
* Kulmarautoja
* Nappula
* Nippuside ja sinitarraa korttien linkomista varten
* Muut osat kuten johdot, ruuvit ja mutterit yms.

## Toimintatavoite

-Robotti jakaa ensin eri puolilla pöytää oleville pelaajille 2 korttia kuvapuoli alaspäin

-Odottaa napin painamista

-Jakaa pöytään 3 korttia vierekkäin kuvapuoli ylöspäin

-Odottaa napin painamista

-Jakaa pöytään 1 kortin kuvapuoli ylöspäin

-Odottaa napin painamista

-Jakaa pöytään 1 kortin kuvapuoli ylöspäin



Toimintaperiaate 

Stepper pyörittää linkoa, joka lähettää kortin eteenpäin. 

Alusta pyörii servon varassa liikkuen seuraavaa pelaajaa kohti.

Toinen servo voi pyörittää korttipakkakoteloa ylösalaisin.
