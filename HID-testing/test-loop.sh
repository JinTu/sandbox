#!/bin/bash

date1=$(date +"%s")
rm test-output.txt

for i in {1..1000}
do
  echo "Iteration $i"
  echo "Iteration $i" >>test-output.txt
  hiddev/bin/test >>test-output.txt
done

date2=$(date +"%s")
diff=$(($date2-$date1))

echo "Test completed in $(($diff / 60)) minutes and $(($diff % 60)) seconds"

FAILURES=`grep "Doh! " test-output.txt |wc -l`


echo "Encountered $FAILURES failures during test ($((($FAILURES / i) * 100))%)"
