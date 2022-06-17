cat filesystem.manifest | cut -d ' ' -f 1 > filesystem.manifest.name
cat filesystem.manifest | cut -d ' ' -f 1 | xargs > filesystem.manifest.name
cat filesystem.manifest.name |awk 'BEGIN{ORS=" "}
{print $0,RT}'>filesystem.manifest.name.oneline
cat filesystem.manifest | cut -d ' ' -f 1 | grep deepin | wc -l
