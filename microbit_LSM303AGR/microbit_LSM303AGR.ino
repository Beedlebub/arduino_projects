/**
 ******************************************************************************
   @file    X_NUCLEO_IKS01A2_LSM303AGR_DataLog_Terminal.ino
   @author  AST
   @version V1.0.0
   @date    7 September 2017
   @brief   Arduino test application for the STMicrolectronics X-NUCLEO-IKS01A2
            MEMS Inertial and Environmental sensor expansion board.
            This application makes use of C++ classes obtained from the C
            components' drivers.
 ******************************************************************************
   @attention

   <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:
     1. Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
     2. Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the documentation
        and/or other materials provided with the distribution.
     3. Neither the name of STMicroelectronics nor the names of its contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
*/


// Includes.
#include <LSM303AGR_ACC_Sensor.h>
#include <LSM303AGR_MAG_Sensor.h>

#if defined(ARDUINO_SAM_DUE)
#define DEV_I2C Wire1   //Define which I2C bus is used. Wire1 for the Arduino Due
#define SerialPort Serial
#else
#define DEV_I2C Wire    //Or Wire
#define SerialPort Serial
#endif

// Components.
LSM303AGR_ACC_Sensor *Acc;
LSM303AGR_MAG_Sensor *Mag;

void setup() {
  // Led.
  pinMode(13, OUTPUT);

  // Initialize serial for output.
  SerialPort.begin(9600);

  // Initialize I2C bus.
  DEV_I2C.begin();

  // Initlialize components.
  Acc = new LSM303AGR_ACC_Sensor(&DEV_I2C);
  Acc->Enable();
  Acc->EnableTemperatureSensor();
  Mag = new LSM303AGR_MAG_Sensor(&DEV_I2C);
  Mag->Enable();
}

void loop() {
  // Led blinking.
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);

  // Read accelerometer LSM303AGR.
  int32_t accelerometer[3];
  Acc->GetAxes(accelerometer);

  // Read temperature LSM303AGR.
  float temperature;
  Acc->GetTemperature(&temperature);

  // Read magnetometer LSM303AGR.
  int32_t magnetometer[3];
  Mag->GetAxes(magnetometer);

  // Output data.
  SerialPort.print("| Acc[mg]: ");
  SerialPort.print(accelerometer[0]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[1]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[2]);
  SerialPort.print(" | Mag[mGauss]: ");
  SerialPort.print(magnetometer[0]);
  SerialPort.print(" ");
  SerialPort.print(magnetometer[1]);
  SerialPort.print(" ");
  SerialPort.print(magnetometer[2]);
  SerialPort.print(" | Temp[C]: ");
  SerialPort.print(temperature, 2);
  SerialPort.println(" |");
}
