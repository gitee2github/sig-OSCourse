#!/bin/bash
ls -Rl / 2>/dev/null | awk '{print $5,$9}' | sort -k1 -nr | head -10
