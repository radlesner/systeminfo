#!/bin/bash
@echo off
mkdir $HOME/.systeminfo-files
sudo ln -s $HOME/.systeminfo-files /systeminfo-files
sudo cp Debug/systeminfo /usr/bin
