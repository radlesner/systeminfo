#!/bin/sh
echo off
mkdir ~/.systeminfo-files
sudo ln -s ~/.systeminfo-files /systeminfo-files
sudo cp Debug/systeminfo /usr/bin