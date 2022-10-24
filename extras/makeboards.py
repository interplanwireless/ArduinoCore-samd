#!/usr/bin/env python3

print('''# Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
''')

mcu_dict = {
    'SAMD21': {
        'flash_size': 262144,
        'data_size': 0,
        'offset': '0x2000',
        'build_mcu': 'cortex-m0plus',
        'f_cpu': '48000000L',
        'extra_flags': '-DARDUINO_SAMD_ZERO -DARM_MATH_CM0PLUS'
    },
    
    'SAMD51': {
        'flash_size': 507904, # SAMD51P20A and SAMD51J20A has 1032192
        'data_size': 0,
        'offset': '0x4000',
        'build_mcu': 'cortex-m4',
        'f_cpu': '120000000L',
        'extra_flags': '-D__SAMD51__ -D__FPU_PRESENT -DARM_MATH_CM4 -mfloat-abi=hard -mfpu=fpv4-sp-d16'
    },
    
    'SAME51': {
        'flash_size': 507904,
        'data_size': 0,
        'offset': '0x4000',
        'build_mcu': 'cortex-m4',
        'f_cpu': '120000000L',
        'extra_flags': '-D__SAMD51__ -D__FPU_PRESENT -DARM_MATH_CM4 -mfloat-abi=hard -mfpu=fpv4-sp-d16'
    },                    
}


def build_header(mcu, name, vendor, product, vid, pid_list):
    prettyname = vendor + " " + product + " ({})".format(mcu)
    print()
    print("# -----------------------------------")
    print("# {}".format(prettyname))
    print("# -----------------------------------")
    print("{}.name={}".format(name, prettyname))
    print()

    print("# VID/PID for Bootloader, Arduino & CircuitPython")
    for i in range(len(pid_list)):
        print("{}.vid.{}={}".format(name, i, vid))
        print("{}.pid.{}={}".format(name, i, pid_list[i]))
    print()

def build_upload(mcu, name, extra_flags):
    print("# Upload")    
    print("{}.upload.tool=bossac18".format(name))
    print("{}.upload.protocol=sam-ba".format(name))
    
    if ('SAMD51P20A' in extra_flags) or ('SAMD51J20A' in extra_flags):
        flash_size = 1032192
    else:
        flash_size = mcu_dict[mcu]['flash_size']
    print("{}.upload.maximum_size={}".format(name, flash_size))
    #print("{}.upload.maximum_data_size=%d".format((name, mcu_dict[mcu]['data_size']))
    
    print("{}.upload.offset={}".format(name, mcu_dict[mcu]['offset']))    
    print("{}.upload.use_1200bps_touch=true".format(name))
    print("{}.upload.wait_for_upload_port=true".format(name))
    print("{}.upload.native_usb=true".format(name))
    print()

def build_build(mcu, name, variant, vendor, product, vid, pid_list, boarddefine, extra_flags, bootloader):
    print("# Build")
    print("{}.build.mcu={}".format(name, mcu_dict[mcu]['build_mcu']))
    print("{}.build.f_cpu={}".format(name, mcu_dict[mcu]['f_cpu']))
    print('{}.build.usb_product="{}"'.format(name, product))
    print('{}.build.usb_manufacturer="{}"'.format(name, vendor))    
    print("{}.build.board={}".format(name, boarddefine))    
    print("{}.build.core=arduino".format(name))    
    print("{}.build.extra_flags={} {} {{build.usb_flags}}".format(name, extra_flags, mcu_dict[mcu]['extra_flags']))
    print("{}.build.ldscript=linker_scripts/gcc/flash_with_bootloader.ld".format(name))    
    print("{}.build.openocdscript=openocd_scripts/{}.cfg".format(name, variant))    
    print("{}.build.variant={}".format(name, variant))
    print("{}.build.variant_system_lib=".format(name))    
    print("{}.build.vid={}".format(name, vid))
    print("{}.build.pid={}".format(name, pid_list[0]))            
    print("{}.bootloader.tool=openocd".format(name))
    print("{}.bootloader.file={}".format(name, bootloader))
    if (mcu == 'SAMD51' or mcu == 'SAME51'):
        print('{}.compiler.arm.cmsis.ldflags="-L{{runtime.tools.CMSIS-5.4.0.path}}/CMSIS/Lib/GCC/" "-L{{build.variant.path}}" -larm_cortexM4lf_math -mfloat-abi=hard -mfpu=fpv4-sp-d16'.format(name))
    print()
    

def build_menu(mcu, name):
    print("# Menu")
    if (mcu == 'SAMD51' or mcu == 'SAME51'):
        print("{}.menu.cache.on=Enabled".format(name))
        print("{}.menu.cache.on.build.cache_flags=-DENABLE_CACHE".format(name))
        print("{}.menu.cache.off=Disabled".format(name))
        print("{}.menu.cache.off.build.cache_flags=".format(name))
        
        print("{}.menu.speed.120=120 MHz (standard)".format(name))
        print("{}.menu.speed.120.build.f_cpu=120000000L".format(name))
        print("{}.menu.speed.150=150 MHz (overclock)".format(name))
        print("{}.menu.speed.150.build.f_cpu=150000000L".format(name))
        print("{}.menu.speed.180=180 MHz (overclock)".format(name))
        print("{}.menu.speed.180.build.f_cpu=180000000L".format(name))
        print("{}.menu.speed.200=200 MHz (overclock)".format(name))
        print("{}.menu.speed.200.build.f_cpu=200000000L".format(name))
    
    print("{}.menu.opt.small=Small (-Os) (standard)".format(name))
    print("{}.menu.opt.small.build.flags.optimize=-Os".format(name))
    print("{}.menu.opt.fast=Fast (-O2)".format(name))
    print("{}.menu.opt.fast.build.flags.optimize=-O2".format(name))
    print("{}.menu.opt.faster=Faster (-O3)".format(name))
    print("{}.menu.opt.faster.build.flags.optimize=-O3".format(name))
    print("{}.menu.opt.fastest=Fastest (-Ofast)".format(name))
    print("{}.menu.opt.fastest.build.flags.optimize=-Ofast".format(name))
    print("{}.menu.opt.dragons=Here be dragons (-Ofast -funroll-loops)".format(name))
    print("{}.menu.opt.dragons.build.flags.optimize=-Ofast -funroll-loops".format(name))
    
    if (mcu == 'SAMD51' or mcu == 'SAME51'):
        print("{}.menu.maxqspi.50=50 MHz (standard)".format(name))
        print("{}.menu.maxqspi.50.build.flags.maxqspi=-DVARIANT_QSPI_BAUD_DEFAULT=50000000".format(name))
        print("{}.menu.maxqspi.fcpu=CPU Speed / 2".format(name))
        print("{}.menu.maxqspi.fcpu.build.flags.maxqspi=-DVARIANT_QSPI_BAUD_DEFAULT=({{build.f_cpu}})".format(name))

    print("{}.menu.usbstack.arduino=Arduino".format(name))
    print("{}.menu.usbstack.tinyusb=TinyUSB".format(name))
    print("{}.menu.usbstack.tinyusb.build.flags.usbstack=-DUSE_TINYUSB".format(name))

    print("{}.menu.debug.off=Off".format(name))
    print("{}.menu.debug.on=On".format(name))
    print("{}.menu.debug.on.build.flags.debug=-g".format(name))
    print()

def build_global_menu():
    print("menu.cache=Cache")
    print("menu.speed=CPU Speed")
    print("menu.opt=Optimize")
    print("menu.maxqspi=Max QSPI")    
    print("menu.usbstack=USB Stack")
    print("menu.debug=Debug")

def make_board(mcu, name, variant, vendor, product, vid, pid_list, boarddefine, extra_flags, bootloader):
    build_header(mcu, name, vendor, product, vid, pid_list)
    build_upload(mcu, name, extra_flags)
    build_build(mcu, name, variant, vendor, product, vid, pid_list, boarddefine, extra_flags, bootloader)    
    build_menu(mcu, name)

build_global_menu()

######################## SAMD21

######################## SAMD51

make_board("SAMD51", "interplan_ib_m4", "ib_dual", 
           "Interplan Co., LTD.", "IB_DUAL", "0x358D", ["0x0100", "0x0102"],
           "IB_DUAL", "-D__SAMD51G19A__ -DCRYSTALLESS -DINTERPLAN_IBDUAL_EXPRESS", "ib_dual/bootloader-ib_dual-ded5501.bin")
           
""""
make_board("SAMD51", "adafruit_itsybitsy_m4", "itsybitsy_m4", 
           "Adafruit", "ItsyBitsy M4", "0x239A", ["0x802B", "0x002B"],
           "ITSYBITSY_M4", "-D__SAMD51G19A__ -DCRYSTALLESS -DADAFRUIT_ITSYBITSY_M4_EXPRESS", "itsybitsyM4/bootloader-itsybitsy_m4-v2.0.0-adafruit.5.bin")
"""