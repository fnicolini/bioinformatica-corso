file_size=$1
file_size_MB=$((file_size * 1000000))
base64 /dev/urandom | head -c $file_size_MB > rand.txt 