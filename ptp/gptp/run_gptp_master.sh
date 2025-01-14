#!/bin/bash

echo "Run gPTP and ph2csys, trying for grand-master role"

if [[ `whoami` != "root" ]]; then
    echo "Run as root/sudo!"; exit -1;
fi

DIR=$(dirname ${BASH_SOURCE})
echo $DIR
echo "Start ptp..."
sudo ptp4l -f $DIR/gPTP_master.cfg -i enp88s0 -m &> $DIR/ptp.log &
echo "ptp4l is running in bg as pid $!"

sleep 2

echo "Start phc2sys..."
sudo phc2sys -c enp88s0 -s CLOCK_REALTIME -m -O 37 &> $DIR/phc2sys.log &
echo "phc2sys (sync NIC clock to sys clock) is running in bg as pid $!"
