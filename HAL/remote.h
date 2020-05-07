//Beta
//*****

#ifndef _REMOTE_H
 #define _REMOTE_H
 /*____________________________________________________________________________________________*/

//Constants
//*********

//States
#define IR_VALIDATE_LEAD_HIGH 0
#define IR_VALIDATE_LEAD_LOW 1
#define IR_RECEIVE_BITS 3
#define IR_WAIT_STOP_BIT 4

//Others
#define TOL 0.1			//Tollerence for timming
#define QMAX 8			//Size of the Remote command buffer
#define RC_NONE 255		//This val is returned by GetRemoteCmd when no key is pressed


//Functions
//*********

void ResetIR();
void RemoteInit();
unsigned char GetRemoteCmd(char wait);

 /*____________________________________________________________________________________________*/
#endif
