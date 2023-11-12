# Question 1

Seed	Result
0		108 -> SEG1(492)
		97  -> SEG1V
		53  -> SEG0V
		33  -> SEG0V
		65  -> SEG1V

1		17  -> SEG0(17)
		108 -> SEG1(492)
		97	-> SEG1V
		32	-> SEG0V
		63  -> SEG0V

2		122 -> SEG1(506)
		121 -> SEG1(505)
		7	-> SEG0(7)
		10	-> SEG0(10)
		106	-> SEG1V

# Question 2

HIghest legal vaddr in segment 0 -> 19
Lowest legal vaddr in segment 1  -> 108

Highest illegal vaddr -> 107
Lowest illegal vaddr -> 20

`python ./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -A 19,108,107,20 -c`

# Question 3

`python ./segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 0 --l0 2 --b1 15 --l1 2 -c`

# Question 4

Die base register auf 0 und sizeof(phys) setzen, die limits auf je 45% des physischen speichers.
Parameter: -a -p --b0 --l0 --b1 --l1

# Question 5

Limits auf 0.