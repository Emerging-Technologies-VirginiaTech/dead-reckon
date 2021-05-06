#!/bin/bash

#bash script used to connect to CAN

# install utils once using: 
# sudo apt-get install can-utils

# enable CAN
sudo modprobe can
sudo modprobe can_raw

# current bitrate set to 500,000
sudo ip link set can0 type can bitrate 500000
sudo ip link set up can0
