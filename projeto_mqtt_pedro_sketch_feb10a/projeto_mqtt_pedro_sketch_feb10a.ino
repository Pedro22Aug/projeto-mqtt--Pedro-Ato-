/* O objetivo desse projeto é fazer com que :

  O Sensor Magnético deva verificar se a porta de um Rack estaja ABERTA ou
FECHADA e exibir essa informação no Monitor Serial.
 

 Utilizando o módulo Ethernet ENC28J60, deve-se conectar o Arduino Uno à
rede e obter um IP via DHCP.


 Com o Arduino conectado à rede, deve-se enviar a informação se a porta do
rack está ABERTA ou FECHADA para um servidor MQTT localizado na AWS,
que terá um Endereço IP especificado .

 Configurar o app MQTT Dash em um Smartphone, onde ele deve receber a
informação do servidor MQTT e exibir na tela a informação do estado da porta
do rack (ABERTA/FECHADA).
*/

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
