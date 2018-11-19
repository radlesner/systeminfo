#!/bin/bash
mkdir $HOME/.systeminfo-files
ln -s $HOME/.systeminfo-files /systeminfo-files
cp Debug/systeminfo /usr/bin
