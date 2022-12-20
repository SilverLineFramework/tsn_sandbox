#!/bin/bash

echo "Run gPTP and ph2csys, assuming client role"

if [[ `whoami` != "root" ]]; then
    echo "Run as root/sudo!"; exit -1;
fi

DIR=$(dirname ${BASH_SOURCE})
echo $DIR
echo "Start ptp..."
sudo ptp4l -f $DIR/gPTP_client.cfg -i enp88s0 -m &> $DIR/ptp.log &
echo "ptp4l is running in bg as pid $!"

#sleep 2

#echo "Start phc2sys..."
# # assume as client configuration for -s and -c and -O
#sudo phc2sys -s enp88s0 -c CLOCK_REALTIME  -m -O -37 &> phc2sys.log & 
#echo "phc2sys (sync NIC clock to sys clock) is running in bg as pid $!"
