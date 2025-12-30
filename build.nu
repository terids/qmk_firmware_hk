#!/usr/bin/env nu

def main [] {
    (
        make
        crkbd/rev1:gleathy:flash
        -e USER_NAME=holykeebs
        -e POINTING_DEVICE=trackball
        -e POINTING_DEVICE_POSITION=right
        -e OLED=yes
        -j8
    )
}
