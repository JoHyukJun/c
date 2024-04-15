#!/bin/bash
# Full search path with HandBrake CLI
# By JO HYUK JUN - 2024.04.15
#
# Usage :
#   'sudo ./handbrake.sh /root-path /destination'
#
ROOT_PATH=$1
PRESET="./NSFW.json"

while IFS= read -d '' -r ITEM
do
    echo "ITEM: $ITEM"
    FILE=${ITEM##*/}
    echo "FILE: $FILE"
    FILE_PATH=${ITEM%/*}
    echo "FILE_PATH: $FILE_PATH"
    EXT=${ITEM##*.}
    echo "EXT: $EXT"
    EXT=$(echo $EXT | tr "[:upper:]" "[:lower:]")
    OUTPUT="$FILE_PATH/${FILE%.*}[hb-cli].$EXT"
    echo "" | HandBrakeCLI -i "$ITEM" -o "$OUTPUT" --preset-import-file $PRESET
done < <(find "$ROOT_PATH" \( -iname '*.mp4' -or -iname '*.avi'  -or -iname '*.mkv' -or -iname '*.mts' -or -iname '*.mov' \) -print0)