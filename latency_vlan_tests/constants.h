/*
MIT License

Copyright (c) 2021 Reese Grimsley

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#define SOURCE_NAME "tsn1"
#define SOURCE_MAC_ADDR {0x48, 0x21, 0x0b, 0x26, 0x20, 0x5e}  //54:b2:03:f0:d4:55
#define SOURCE_IP_ADDR "192.168.1.86"
#define SOURCE_IP_ADDR_VLAN3 "10.0.3.101"
#define SOURCE_IP_ADDR_VLAN5 "10.0.5.101"
#define SINK_NAME 'tsn2'
#define SINK_MAC_ADDR {0x48, 0x21, 0x0b, 0x26, 0x1f, 0xa1}  //54:b2:03:f0:d5:0b
#define SINK_IP_ADDR "192.168.1.215"
#define SINK_IP_ADDR_VLAN3 "10.0.3.102"
#define SINK_IP_ADDR_VLAN5 "10.0.5.102"
#define SINK_PORT 15810
#define JAMMER_NAME "tsn3"
#define JAMMER_MAC_ADDR {0x48, 0x21, 0x0b, 0x26, 0x1f, 0xdf}  //54:b2:03:f0:d4:68
#define JAMMER_IP_ADDR  "192.168.1.87"
#define JAMMER_IP_ADDR_VLAN3 "10.0.3.103"
#define JAMMER_IP_ADDR_VLAN5 "10.0.5.103"
#define JAMMER_PORT 15811

#define ETH_INTERFACE_I225 "enp87s0\0"
#define ETH_INTERFACE_I225_VLAN3 "enp87s0.3\0"
#define ETH_INTERFACE_I225_VLAN5 "enp87s0.5\0"

//to swap VLANs, change the numbers in the next few lines to 3 or 5 or whatever you have created. This helps bind to the correct IP for a VLAN when configuring the socket
#define VLAN_ID 5
#define SOURCE_IP_ADDR_VLAN SOURCE_IP_ADDR_VLAN5
#define SINK_IP_ADDR_VLAN SINK_IP_ADDR_VLAN5
#define JAMMER_IP_ADDR_VLAN JAMMER_IP_ADDR_VLAN5
#define IF_NAME ETH_INTERFACE_I225_VLAN5

#define MAX_FRAME_SIZE 1500
#define MAX_FRAME_DATA_LEN 1360
#define MAX_UDP_PACKET_SIZE 1360
#define MAX_TCP_PACKET_SIZE 150

//37 as of Nov. 5 2021. This will change, but not until at least June 30/2022. Should be updated or read from the system. NICs are sync'd to TAI which is LEAP_SECONDS_FFSET ahead of UTC, which the RTC/CLOCK_REALTIME reads.
#define LEAP_SECONDS_OFFSET 37 

//From openAVNU; does not seem to correspond to any well-known types of ethernet message/protocol.
// https://github.com/torvalds/linux/blob/master/include/uapi/linux/if_ether.h
#define MVRP_ETYPE 0x88F5 //this one exists in the kernel
#define MSRP_ETYPE 0x22EA // close to ETH_TSN (0x22f0)
#define MMRP_ETYPE 0x88F6
#define ETH_P_VLAN ETH_P_8021Q // or ETH_P_8021AD?
#define ETH_P_JAMMER 0x89FF // something unique that will not conflict with other frame type

#define LATENCY_SAMPLES_TO_LOG 1000
