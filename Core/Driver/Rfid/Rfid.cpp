#include "main.h"
#include "Rfid.h"
#include "utils.h"
#include "module.h"
#include "Config/pins.h"
#include "Types/millis.h"

namespace ferroni {

Rfid::Rfid(){
    _rfid_dev = Adafruit_MFRC630(&i2c, 0x2B << 1, PDOWN_GPIO_Port, PDOWN_Pin);
	instance = this;
    state = State::Start;  
}

void Rfid::updateStart() {
    if (!(_rfid_dev.begin())) {
    }
    

    _rfid_dev.write8(0x00, 0x1F);
    HAL_Delay(50);
    // _rfid_dev.configRadio(MFRC630_RADIOCFG_ISO1443A_106);

    _rfid_dev.write8(0x00, 0x00);

    _rfid_dev.write8(0x06, 0x7F);
    _rfid_dev.write8(0x07, 0x7F);
    _rfid_dev.write8(0x08, 0x00);
    _rfid_dev.write8(0x09, 0x00);
    _rfid_dev.write8(0x02, 0xB0);
    
    _rfid_dev.write8(0x3F, 0xC0);
    _rfid_dev.write8(0x40, 0xFF);
    _rfid_dev.write8(0x41, 0xC0);
    _rfid_dev.write8(0x28, 0x89);
    
    _rfid_dev.write8(0x1F, 0x00);
    _rfid_dev.write8(0x20, 0x10);
    _rfid_dev.write8(0x24, 0x00);
    _rfid_dev.write8(0x25, 0x05);
    _rfid_dev.write8(0x23, 0xF8);
    _rfid_dev.write8(0x43, 0x40);
    _rfid_dev.write8(0x38, 0x52);
    _rfid_dev.write8(0x39, 0x03);
    _rfid_dev.write8(0x00, 0x01);
    // _rfid_dev.write8(0x08, 0x00);
    // _rfid_dev.write8(MFRC630_REG_IRQ1, 0b00111111);
    // _rfid_dev.write8(MFRC630_REG_IRQ1EN, MFRC630IRQ1_LPCDIRQ);

    // HAL_Delay(50);
    _rfid_dev.write8(0x00, 0x00);
    _rfid_dev.write8(0x02, 0xB0);
    _rfid_dev.write8(0x38, 0x12);

    uint8_t I = _rfid_dev.read8(0x42);
    uint8_t Q = _rfid_dev.read8(0x43);
    uint8_t TH = 1;
    uint8_t r_3F = (((I+TH)&0x30)<<2)|(Q-TH);
    uint8_t r_40 = (((I+TH)&0x0C)<<4)|(Q+TH);
    uint8_t r_41 = (((I+TH)&0x03)<<6)|(I-TH);

    HAL_Delay(50);
    //Detect PICC
    _rfid_dev.write8(0x3F, r_3F);
    _rfid_dev.write8(0x40, r_40);
    _rfid_dev.write8(0x41, r_41);

    
    // _rfid_dev.write8(0x3F, 0x6A);
    // _rfid_dev.write8(0x40, 0x2C);
    // _rfid_dev.write8(0x41, 0xD1);

    _rfid_dev.write8(0x1F, 0x07);
    _rfid_dev.write8(0x20, 0xF2);
    _rfid_dev.write8(0x24, 0x00);
    _rfid_dev.write8(0x25, 0x13);
    _rfid_dev.write8(0x23, 0xDF);
    _rfid_dev.write8(0x43, 0x40);
    _rfid_dev.write8(0x38, 0x52);

    _rfid_dev.read8(0x39);
    _rfid_dev.write8(0x39, 0x03);

    while(_rfid_dev.read8(0x23) & 0x80 != 0x80);
    // HAL_Delay(50);
    
    _rfid_dev.write8(0x0, 0x0);
    _rfid_dev.write8(0x02, 0xB0);
    _rfid_dev.write8(0x06, 0x7F);
    _rfid_dev.write8(0x07, 0x7F);
    _rfid_dev.write8(0x08, 0x10);
    _rfid_dev.write8(0x09, 0x60);
    _rfid_dev.write8(0x00, 0x81);

    while(1)
        _rfid_dev.read8(0x0);

    state = State::Idle;
}
void Rfid::updateIdle() {
}

void Rfid::update() {
	SWITCH_STATE(state, RFID_STATES);

    // _rfid_dev.write8(0x00, 0x01);
    // _rfid_dev.softReset();                                  //Put the IC in a known-state.
    // _rfid_dev.configRadio(MFRC630_RADIOCFG_ISO1443A_106);   // Configure the radio for ISO14443A-106.

    // uint16_t atqa = _rfid_dev.iso14443aRequest();           //Request a tag (activates the near field, etc.).
    // if (atqa)                                               //Looks like we found a tag, move on to selection.
    // {
    //     uint8_t uid[10] = {0};
    //     uint8_t uidlen;
    //     uint8_t sak;
    //     uidlen = _rfid_dev.iso14443aSelect(uid, &sak);      //Retrieve the UID and SAK values.
    //     if (uidlen == 4) {
    //         done();
    //     }
    // }
}

bool Rfid::done() {
	return state == State::Idle;
}

Rfid* Rfid::instance;
}