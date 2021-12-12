#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2    // 告訴 OneWire library DQ 接在那隻腳上

OneWire oneWire(ONE_WIRE_BUS); // 建立 OneWire 物件

DallasTemperature DS18B20(&oneWire); // 建立 DS18B20 物件

void setup(void){
  pinMode(7, OUTPUT);
  DS18B20.begin();
  Serial.begin(9600);
}

void loop(void){

  float temperature; //注意，溫度讀值帶小數，要用 float
  DS18B20.requestTemperatures();  //下指令開始轉換
  temperature = DS18B20.getTempCByIndex(0);  //讀取第一顆 DS18B20 的溫度
  Serial.print(temperature);
  Serial.print("\n");
  if (temperature > 60) {
     digitalWrite(7, LOW);
  } else {
     digitalWrite(7, HIGH);
  }
  delay(1000);
}
