# Care-Me
## Technologies: Google Speech Recognition, Raspberry Pi, Arduino, NRF24 Transcievers, Photoresistor
## Slide Deck: https://docs.google.com/presentation/d/1eTqlBnw55R_p30AgqeskgCULWnSZlK-mGh8LVKd8J1U/edit?usp=sharing
### Speech.py
  - uses Google Cloud libraries to process input from webcam microphone recording
  - button activated
  - microphone is recorded via bash script call
### robot.ino  
  - initiates robot movement upon reciept of radio transcievers
  - sensor to detect lines and follow lines based on light (photo resistor)
  - DC motors apply high torque to handle more load and reliablity 
