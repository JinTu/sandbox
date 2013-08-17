#!/bin/bash

date1=$(date +"%s")
rm test-output.txt

for i in {1..1000}
do
  echo "Iteration $i"
  echo "Iteration $i" >>test-output.txt
  hiddev/bin/test >>test-output.txt
  # We need to give the USB bus a little break or things can hang
  #sleep 1
done

date2=$(date +"%s")
diff=$(($date2-$date1))

echo "Test completed in $(($diff / 60)) minutes and $(($diff % 60)) seconds"

FAILURES=$(grep "Doh! " test-output.txt |wc -l)
ATTEMPTS=$(grep "Attempt " test-output.txt |wc -l)

PERCENT_FAILED=$(echo "scale=4; ($FAILURES / $i) * 100" | bc -q 2>/dev/null)
ATTEMPT_SUCCEDED=$(echo "scale=2; ($i / $ATTEMPTS) * 100" | bc -q 2>/dev/null)
echo "Encountered $FAILURES failures during test ($PERCENT_FAILED%). Attempt success rate $ATTEMPT_SUCCEDED%"

