#!/bin/bash
# ------------------------------------------------------------------------------------------
# switchip.cmd - batch script to switch the ip address on the ethernet adapter 10, so I
# don't have to go into settings->network settings->ethernet->change ethernet adaptapter->
# IP v4 and switch manually the ip. typing into a terminal with administrator rights
# "switchip.cmd" is way quicker then the visual way.
# ------------------------------------------------------------------------------------------
# author:     Patrik Eigenmann
# email:      p.eigenmann@gmx.net
# ------------------------------------------------------------------------------------------
# Change Log:
# Monday 2024-11-04 File created.                                              Version 00.01
# ------------------------------------------------------------------------------------------

echo "Select an option:"
echo "1. Set IP to 192.168.1.100 / 255.252.0.0"
echo "2. Set IP to 10.248.0.100 / 255.252.0.0"
echo "3. Exit"
read -p "Enter choice (1/2/3): " choice

case $choice in
    1)
        echo "Setting IP to 192.168.1.100 / 255.252.0.0"
        sudo ifconfig en0 inet 192.168.1.100 netmask 255.252.0.0
        ;;
    2)
        echo "Setting IP to 10.248.0.100 / 255.252.0.0"
        sudo ifconfig en0 inet 10.248.0.100 netmask 255.252.0.0
        ;;
    3)
        echo "Exiting"
        exit 0
        ;;
    *)
        echo "Invalid choice"
        exit 1
        ;;
esac

echo "Done."