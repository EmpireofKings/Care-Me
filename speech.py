import os
import datetime
import sys

import subprocess
import RPi.GPIO as GPIO
from time import sleep
from gpiozero import Button
from lib_nrf24 import NRF24
import spidev
import io
import sys

def transcribe_file(speech_file):
    """Transcribe the given audio file."""
    from google.cloud import speech
    from google.cloud.speech import enums
    from google.cloud.speech import types
    
    client = speech.SpeechClient() 

    with io.open(speech_file, 'rb') as audio_file:
        content = audio_file.read()

    audio = types.RecognitionAudio(content=content)
    config = types.RecognitionConfig(
        encoding=enums.RecognitionConfig.AudioEncoding.LINEAR16,
        language_code='en-US')

    response = client.recognize(config, audio)
    # Each result is for a consecutive portion of the audio. Iterate through
    # them to get the transcripts for the entire audio file.
    for result in response.results:
        # The first alternative is the most likely one for this portion.
        return(str(result.alternatives[0].transcript))
        


button = Button(2) #button enabled loop - setting pin for button
"""GPIO.setmode(GPIO.BCM)

pipes = [[0xE8, 0xE8, 0xF0, 0xF0, 0xE1], [0xF0, 0xF0, 0xF0, 0xF0, 0xE1]]

radio = NRF24(GPIO, spidev.SpiDev())
radio.begin(0, 17)

radio.setPayloadSize(32)
radio.setChannel(0x76)
radio.setDataRate(NRF24.BR_1MBPS)
radio.setPALevel(NRF24.PA_MIN)

radio.setAutoAck(True)
radio.enableDynamicPayloads()
radio.enableAckPayload()

radio.openWritingPipe(pipes[0])
radio.openReadingPipe(1, pipes[1])
radio.printDetails()
#radio.startListening()

deliver = list("GETSTRING")
while len(deliver) < 32:
    deliver.append(0)"""
while True:
    button.wait_for_press() #loop runs when button is pressed
    print("Button pushed")
    """start.time.time()
    #radio.write(deliver)
    print("Sent the message: {}".format(deliver))
    print(deliver)
    radio.startListening()

    while not radio.available(0)
        time.sleep(1/100)
        if time.time() - start > 2
            print("Timed out")
            break
    recievedMessage = []
    radio.read(recievedMessage, radio.getDynamicPayloadSize())
    print("R: {}".format(recievedMessage)
    print("Translating our received Message into unicode characters...")
    string = ""

    for n in receivedMessage:
        if (n >= 32 and n <= 126):
            string += chr(n)
    print("Our received message decodes to: {}".format(string))

    radio.stopListening()
    time.sleep(1)"""     
    #records audio file
    os.system('./audiorecorder.sh') #executes bash file that records audio from webcam microphone 
    message = transcribe_file('audio.wav')
    print(message)
    #checks different keywords of requests
    if "water" in message:
        #send true command
        print("Water Requested")
    elif "lunch" in message:
        #send
        print("Lunch Requested")
    else:
        print("No Request Made")
    
    
