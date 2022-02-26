#!/bin/bash
set -e

if [ ! -f edges.json ]; then
	echo "edges.json not found"
	exit
fi

if [ ! -f matched-segments-data.csv ]; then
	echo "not-found-edges.csv not found"
	exit
fi

if [ $# -ne 2 ]; then
	echo "./sharedstreets.sh output-before-IQR.csv"
	exit 1
fi

input_csv="$1"
output_csv="${1%.*}-sh-sp.csv"

declare -a shared_streets
edge_ids="$(jq '.edges[].id' -r <edges.json)"

rm ./not-found-edges.csv || true

for edge_id in $edge_ids; do
	echo "===================== $edge_id ====================="
	while read -r row; do
		if [ -z "$row" ]; then
			echo "there isn't any $edge_id :("
			echo "$edge_id" >>./not-found-edges.csv
			continue
		fi
		echo "row: $row"
		readarray -d ',' -t row <<<"$row"
		echo "colums: ${row[*]}"
		shared_street="${row[0]}"
		echo "we have shared_street on $shared_street"
		shared_streets+=("$shared_street")
	done <<<"$(grep "$edge_id" matched-segments-data.csv)"
	echo "=================================================="
	echo
	echo
done

rm "$output_csv" || true

echo "sharedstreet,$(seq -s',' 0 671)" >"$output_csv"

for shared_street in "${shared_streets[@]}"; do
	echo "shared_street: $shared_street"
	grep "$shared_street" "$input_csv" >>"$output_csv" || {
		echo "$shared_street" >"$output_csv"
		printf '0,%.0s' {0..670} >"$output_csv"
		echo "0" >"$output_csv"
	}
done
