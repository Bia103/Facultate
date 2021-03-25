.data
	n:.word 4
	v:.word 7,3,1,1
.text
main:
	lw $t0,n
	
	subu $sp,$sp,4
	sw $t0,0($sp)
	li $t1,0
	mulo $t3,$t0,4
	sw $fp,0($sp)
	addi $t3,$t3,-4
	
for1:
	bgt $t1,$t3,continua1
	lw $t2,v($t1)
	subu $sp,$sp,4
	sw $t2,0($sp)
	addi $t1,$t1,4
	j for1
	
	
	
continua1:	
	jal bubble
	li $t1,-4
for2:
	addi $t1,$t1,4
	lw $a0,v($t1)
	li $v0,1
	syscall
	bgt $t3,$t1,for2
	li $v0, 10 
	syscall
bubble:
	lw $t2,0($fp)
	li $t0,4 #cu asta inaintez in vector
	mulo $t3,$t2,$t0 
	addi $t3,$t3,-4
	#li $t4,0 
	
do:
	li $t1,1
	li $t4,4 #i
	for: 
		addi $t5,$t4,-4
		
	
	
		lw $t6,v($t5)
		lw $t7,v($t4)
		
		bge $t7,$t6,decizie 
		sw  $t6,v($t4)
		sw  $t7,v($t5)
		li $t1,0
	decizie:
	addi $t4,$t4,4
	bgt $t4,$t3,continua
	
	j for
	continua :
	beq $t1,$0,do
	#j final
jr $ra
