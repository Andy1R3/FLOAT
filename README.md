#sensori Float
## Sensore di pressione e temperatura
Il sensore di pressione e temperatura che utilizziamo per il float è il [BAR02](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar02-sensor-r1-rp/) 
della BlueRobotics. 
Il sensore utilizza il protocollo i2c per la comunicazione, quindi sfrutta le porte SCL e SDA della scheda (oltre che alimentazionew e ground)
Inoltre, nonostante il sensore lavori di fattpo a tensioni che vanno da 3.3v a 5v, per il momento utilizzaimo un i2c level converter per connetterlo all'arduino nano 
in modo da connettere fisicamente il connettore del sensore alla scheda.
### Arduino e IDE
La scheda che utiliziamo nel float è un [Arduino Nano RP2040 Connect](https://docs.arduino.cc/hardware/nano-rp2040-connect/), perciò per scrivere i programmi e 
successivamente caricarli nella scheda è necessario utilizzare l'[ambiete di programmazione integrato proprietario](https://www.arduino.cc/en/software).
Con le ultime verisoni dell'ide, da quello che ho capito, la scheda, a seuguito dell'installazione dell'Arduino Mbed OS Nano Boards, dovrebbe riconoscere automaticamente la scheda e connettersi; 
altrimenti si procede alla vecchia maniera e dalla sezione Strumenti si seleziona a mano la specifica scheda e la porta COM con cui avviene il collegamento.
