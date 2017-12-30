#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
                           // as described in the footer comment below


int val = 0;
int val2 = 0; 
int val3 = 0;



// Note that for additional security and reusability, you could
// use #define statements to specify these values in a .h file.

// your Gmail username, formatted as a complete email address, eg "bob.smith@gmail.com"
const String GMAIL_USER_NAME = "";

// your application specific password (see instructions above)
const String GMAIL_APP_PASSWORD = "";

// the email address you want to send the email to, eg "jane.doe@temboo.com"
const String TO_EMAIL_ADDRESS = "";

// a flag to indicate whether we've tried to send the email yet or not
boolean attempted = false; 

void setup() {
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(7, OUTPUT);
pinMode(13, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
  Bridge.begin();
}

void loop(){
 digitalWrite(13, HIGH);
val = digitalRead(2); 
val2 = digitalRead(3);
val3 = digitalRead(4); 
if (val == HIGH) {      
    digitalWrite(7, HIGH);
    
    TembooChoreo SendEmailChoreo;

    // invoke the Temboo client
    // NOTE that the client must be reinvoked, and repopulated with
    // appropriate arguments, each time its run() method is called.
    SendEmailChoreo.begin();
    
    // set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Gmail > SendEmail)
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
 

    // set the required choreo inputs
    // see https://www.temboo.com/library/Library/Google/Gmail/SendEmail/ 
    // for complete details about the inputs for this Choreo

    // the first input is your Gmail email address.     
    SendEmailChoreo.addInput("Username", GMAIL_USER_NAME);
    // next is your application specific password
    SendEmailChoreo.addInput("Password", GMAIL_APP_PASSWORD);
    // who to send the email to
    SendEmailChoreo.addInput("ToAddress", TO_EMAIL_ADDRESS);
    // then a subject line
    SendEmailChoreo.addInput("Subject", "Arduino ALERT");

     // next comes the message body, the main content of the email   
    SendEmailChoreo.addInput("MessageBody", "Arduino Alert Contact: 1");

    // tell the Choreo to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendEmailChoreo.run();

    SendEmailChoreo.close();
    delay(5000);
}

else if (val2 == HIGH) {         
    digitalWrite(6, HIGH);
    
    TembooChoreo SendEmailChoreo;

    // invoke the Temboo client
    // NOTE that the client must be reinvoked, and repopulated with
    // appropriate arguments, each time its run() method is called.
    SendEmailChoreo.begin();
    
    // set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Gmail > SendEmail)
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
 

    // set the required choreo inputs
    // see https://www.temboo.com/library/Library/Google/Gmail/SendEmail/ 
    // for complete details about the inputs for this Choreo

    // the first input is your Gmail email address.     
    SendEmailChoreo.addInput("Username", GMAIL_USER_NAME);
    // next is your application specific password
    SendEmailChoreo.addInput("Password", GMAIL_APP_PASSWORD);
    // who to send the email to
    SendEmailChoreo.addInput("ToAddress", TO_EMAIL_ADDRESS);
    // then a subject line
    SendEmailChoreo.addInput("Subject", "Arduino ALERT");

     // next comes the message body, the main content of the email   
    SendEmailChoreo.addInput("MessageBody", "Arduino Alert Contact: 2");

    // tell the Choreo to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendEmailChoreo.run();

    SendEmailChoreo.close();
    delay(5000);
}
else if (val3 == HIGH) {        
    digitalWrite(5, HIGH);
    
    TembooChoreo SendEmailChoreo;

    // invoke the Temboo client
    // NOTE that the client must be reinvoked, and repopulated with
    // appropriate arguments, each time its run() method is called.
    SendEmailChoreo.begin();
    
    // set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

    // identify the Temboo Library choreo to run (Google > Gmail > SendEmail)
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
 

    // set the required choreo inputs
    // see https://www.temboo.com/library/Library/Google/Gmail/SendEmail/ 
    // for complete details about the inputs for this Choreo

    // the first input is your Gmail email address.     
    SendEmailChoreo.addInput("Username", GMAIL_USER_NAME);
    // next is your application specific password
    SendEmailChoreo.addInput("Password", GMAIL_APP_PASSWORD);
    // who to send the email to
    SendEmailChoreo.addInput("ToAddress", TO_EMAIL_ADDRESS);
    // then a subject line
    SendEmailChoreo.addInput("Subject", "Arduino ALERT");

     // next comes the message body, the main content of the email   
    SendEmailChoreo.addInput("MessageBody", "Arduino Alert Contact: 3");

    // tell the Choreo to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendEmailChoreo.run();

    SendEmailChoreo.close();
    delay(5000);


} else {
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
delay(1000);
}
}

