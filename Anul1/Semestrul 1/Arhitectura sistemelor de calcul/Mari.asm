.data
	k:.word 178
	v:.word 0,0,0,0,0,0,0
	b:.word 16
.text
main:

jal baza
li $t1,-4
li $t3,24
for2:
	addi $t1,$t1,4
	lw $a0,v($t1)
	li $v0,1
	syscall
	bgt $t3,$t1,for2
	li $v0, 10 
	syscall
li $v0,10
syscall

baza:
lw $t2,k
lw $t0,b
li $t4,0
for:
div $t2,$t0
mfhi $t3
mflo $t2
sw  $t3,v($t4)
addi $t4,$t4,4
bgtz $t2,for
#div $t2,$t0



jr $ra