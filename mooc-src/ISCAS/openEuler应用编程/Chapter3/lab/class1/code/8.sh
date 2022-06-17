#!/bin/bash
find ./ -size +50k -type f | tee file_list |wc -l
