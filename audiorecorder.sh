#!/bin/bash

arecord --device=plughw:1,0 --duration=7 --format S16_LE audio.wav

