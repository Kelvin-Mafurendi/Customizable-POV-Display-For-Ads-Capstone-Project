#include "mbed.h"
#include "ShiftOut.h"


#define SET_LATCH() (LATCH = 0)
#define RESET_LATCH() (LATCH = 1)

#define ENABLE_RESET() (RESET = 0)
#define DISABLE_RESET() (RESET = 1)

static char stateArr[8*REGISTER_CNT] = {0};
static bool hasChanged = false;


ShiftOut::ShiftOut(PinName ser, PinName srclk, PinName rclk, 
                   PinName oe, PinName reset) : DSERIAL(ser), SRCLK(srclk), RCLK(rclk), LATCH(oe), RESET(reset)
{
    writeByte(0x00); // Reset the values of the registers to 0  
    if(RESET != NC){  
    DISABLE_RESET();
    }
}

//Pulses the register
void ShiftOut::updateRegister(){
    SRCLK = 1;
    RCLK = 1;
    //wait_us(2000);
        
}
//Updates the output register
void ShiftOut::updateOutput(){
    
    //wait_us(20000);
    SRCLK = 0;
    RCLK = 0;  
      
}
//Writes a byte to the shift register
void ShiftOut::writeByte(unsigned char byte){
   // RESET =0;
    hasChanged = true;
    for(int i = 0; i<(8*REGISTER_CNT)+1; i++){
        DSERIAL = (byte & 0x01<<i)>>i;
        updateRegister();    
    } 
    wait_us(2000);
    updateOutput();
    //RESET =1;

}
//Writes a bit to the shift register
void ShiftOut::writeBitRight(unsigned char bit){
    //RESET =0;
    DSERIAL = bit & 0x01;//LSB
    updateRegister();
    wait_us(1);
    updateOutput();
    //RESET =1;
    } 
    //Writes a bit to the shift register
void ShiftOut::writeBitLeft(unsigned char bit){
    //RESET =0;
    DSERIAL = bit & 0x01;//MSB
    updateRegister();
    wait_us(1);
    updateOutput();
    //RESET =1;
    } 
//Writes multiple bits from an array to create an animation
void ShiftOut::animate(int arr[9][5], int lines, int delay_us){
    hasChanged = true;
    
    for(int j = 0; j < 5; j++){
        //RESET =0;
       for(int i = 0; i < lines; i++){
        
           writeBitRight(arr[i][j]);
           
        } 
        wait_us(delay_us);
        //RESET =1; 
        
    }
}

/*void ShiftOut::animationExample(){
    hasChanged = true;
    int strobe[8][5]= {{1,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,0,0},
                     {0,0,1,0,0,0,0,0},
                     {0,0,0,1,0,0,0,0},
                     {0,0,0,0,1,0,0,0},
                     {0,0,0,0,0,1,0,0},
                     {0,0,0,0,0,0,1,0},
                     {0,0,0,0,0,0,0,1}};
                     
    int nightrider[18][5]= {{1,0,0,0,0,0,0,0},
                           {1,1,0,0,0,0,0,0},
                           {1,1,1,0,0,0,0,0},
                           {0,1,1,1,0,0,0,0},
                           {0,0,1,1,1,0,0,0},
                           {0,0,0,1,1,1,0,0},
                           {0,0,0,0,1,1,1,0},
                           {0,0,0,0,0,1,1,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,0,0,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,1,1,1},
                           {0,0,0,0,1,1,1,0},
                           {0,0,0,1,1,1,0,0},
                           {0,0,1,1,1,0,0,0},
                           {0,1,1,1,0,0,0,0},
                           {1,1,1,0,0,0,0,0},
                           {1,1,0,0,0,0,0,0}};
                        
        animate(nightrider, 18, 50);
        wait_us(1000000);
        animate(strobe, 8, 200);
    }*/
    
void ShiftOut::writeBitAtPos(unsigned char pin, bool state){
    if(hasChanged){
        clearStateArray();
        hasChanged = false;
    } 
    if(pin < (8*REGISTER_CNT)+1){
        stateArr[pin] = state;        
    }
    writeArrayRight(stateArr);
}

void ShiftOut::writeArrayRight(char arr[8*REGISTER_CNT]){
    //RESET =0;
    for(int i = (8*REGISTER_CNT)+1; i >= 0; i--) {
        
        writeBitRight(arr[i]);
        //wait_us(1);
        //RESET = 1;  
    }   
      
    
}
void ShiftOut::writeArrayLeft(char arr[8*REGISTER_CNT]) {
    for (int i = (8 * REGISTER_CNT) +1; i >= 0; i--) {
        //RESET = 1;
        writeBitLeft(arr[i]);
        //wait_us(1);
        //RESET = 0;
    }
}
    


void ShiftOut::clearStateArray(){
    for(int i = 0; i <(8*REGISTER_CNT)+1; i++){
        stateArr[i] = 0;
        }
    }





