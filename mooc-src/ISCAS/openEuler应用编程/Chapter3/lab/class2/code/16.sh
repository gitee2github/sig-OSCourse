#!//bin/bash

find ./* -maxdepth 0 -size +10c -exec mv -i "{}" /tmp ";"
