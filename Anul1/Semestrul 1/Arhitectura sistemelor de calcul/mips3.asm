.data
	n:.word 4
	v:.word 7,9,1,1
.text
main:
	lw $t3,n #n
	li $t0,4 
	mulo $t3,$t3,$t0 
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
final:
	li $t1,0
	lw $a0,v($t1)
	li $v0,1
	syscall
	li $t1,4
	lw $a0,v($t1)
	li $v0,1
	syscall
	li $t1,8
	lw $a0,v($t1)
	li $v0,1
	syscall
	li $t1,12
	lw $a0,v($t1)
	li $v0,1
	syscall
	li $v0, 10 
	syscall
