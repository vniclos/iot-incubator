
#include "ClsMod_Act_Relay.h"

// 1 Mode Manual
// 2 Mode Automatic
ClsMod_Act_Relay::ClsMod_Act_Relay(void) {
  m_stdDefault = RELAY_OFF;
  m_pinRele = 0;
};


ClsMod_Act_Relay::~ClsMod_Act_Relay(void) {}

void ClsMod_Act_Relay::setup(unsigned short usPinRele, unsigned short usId)
{
  //,RL_OFF, DEF_MOD_PRGRELMODE_MANUALOFF,,,
  // por omision apagado, en el bucle se calcuara el estado correcto.
  m_pinRele = usPinRele;    // Pin al que esta conectado el rele
  digitalWrite (m_pinRele, RELAY_OFF); //APAGAR RELE POR DEFERCT
  m_Id = usId;
  pinMode(m_pinRele, OUTPUT);


}
void  ClsMod_Act_Relay::loop(unsigned long uiIngtervalNow, float act_temperature, float temperature_min, float temperature_max) {


  if (uiIngtervalNow < m_interval_previous)
  {
    m_interval_previous = 0;
  }
  if (uiIngtervalNow - m_interval_previous < INTERVAL_RELAY)
  {

    return;
  }
  m_interval_previous = uiIngtervalNow;
  // Aqui actualiazar estado
  float temp = temperature_min ;
  if (digitalRead(m_pinRele) == RELAY_ON)
  {
    float temp = temperature_max ;
  }

    if ( act_temperature >= temp) {
      Serial.print	(act_temperature);
      Serial.print (">=");
      Serial.println (temp);
      fncSetSts(RELAY_OFF);
    }
    else {
      Serial.print  (act_temperature);
      Serial.print ("<");
      Serial.println (temp);

      fncSetSts(RELAY_ON);
    }

#ifdef STD_DEBUG_ACT_RELAY

    fncDebug();
#endif

  }

  unsigned short  ClsMod_Act_Relay::fncGetSts() {

    if ( digitalRead(m_pinRele) == RELAY_ON) return RELAY_ON;
    return RELAY_OFF;

  }
  void ClsMod_Act_Relay::fncSetSts( unsigned short bStatusOnOff) {
    unsigned short usRELAY_ON = RELAY_ON;

    if (digitalRead(m_pinRele) == bStatusOnOff) {
      return;
    }

    if (bStatusOnOff == RELAY_ON)
    {
      digitalWrite (m_pinRele, RELAY_ON);


    }

    else {

      digitalWrite (m_pinRele, RELAY_OFF);

    }
    /*
      Serial.println("OFF");
      Serial.print("m_Id=");
      Serial.print(m_Id);
      Serial.print(" m_pinRele=");
      Serial.print(m_pinRele);
      Serial.print(" bStatusOnOf=" );
      Serial.print(bStatusOnOff );
      Serial.print(" digitalReads= ");
      Serial.println(digitalRead(m_pinRele);
      Serial.println("---");
    */
  }
#ifdef STD_DEBUG_ACT_RELAY
  void ClsMod_Act_Relay::fncDebug()
  {

    //Serial.print("Relay pin ");
    //Serial.print(m_pinRele);
    //Serial.print( " Status ");
    //Serial.println(digitalRead(m_pinRele));

  }
#endif
