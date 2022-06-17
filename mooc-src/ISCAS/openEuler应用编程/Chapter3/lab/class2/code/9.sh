#!/bin/bash
ps aux | awk ‘if NR!=1 ‘{print $11, $3}’ | sort –nr –k 2 | head -5
