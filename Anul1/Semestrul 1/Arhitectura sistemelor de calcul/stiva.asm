.data
n: .word 6
k: .word 3
#rezultat: .word 0

.text
main:
	lw $t1,n
	lw $t2,k
	#lw $t3,rezultat
	addi $t3, $zero, 0
	subi $sp,$sp,16
	sw $t3,0($sp)
	sw $t1,8($sp)
	sw $t2,12($sp)
	jal rezolvare
	lw $t3,0($sp)       #t3=rezultat
	addi $sp, $sp, 16   #pop t3, ra, t1, t2
	
	
	li $v0,1
	move $a0, $t3       #printeaza t3
	syscall


li $v0,10                   #sfarsit de program
syscall

rezolvare:
	sw $ra,4($sp)            #se pune sau rescrie ra in stiva
	lw $t1,8($sp)            #se transmite n ca parametru prin stiva
	lw $t2,12($sp)           #se transmite k ca parametru prin stiva
	
	#subi $t2,$t2,1
	#subi $sp,$sp,4
	#sw $ra,0($sp)
	beq $t2,$0,return         #if (k==0) return 1
	beq $t2,$t1,return        #if (n==k) return 1   
	subi $t1,$t1,1              #n = n-1
	subi $sp,$sp,16
	addi $t3,$zero,0          #reinitializarea lui t3 cu 0
	sw $t3,0($sp)             
	sw $t1,8($sp)
	sw $t2,12($sp)
	jal rezolvare              #se va compara n-1 si k
	lw $t4,0($sp)
	lw $t5,16($sp)             #se rescrie t3 de pe pozitia 16 (4 casute in spate)
	                             # cu t3 +1
	add $t4,$t5,$t4
	sw $t4,16($sp)
	#lw $ra,4($sp)
	#addi $sp,$sp,16
	#subi $sp,$sp,16 
	#addi $t3,$zero,0
	#sw $t3,0($sp)
	#sw $ra,4($sp)
	#sw $t1,8($sp)
	#sw $t2,12($sp)
	lw $t4,0($sp)
	addi $t4,$0,0
	sw $t4,0($sp)         #reinitializarea lui t3 cu 0 si rescrierea lui in stiva
	lw $t2,12($sp)
	subi $t2,$t2,1        #k = k-1
	sw $t2,12($sp)        #rescrierea lui k in stiva cu k-1
	jal rezolvare         #se va compara n-1 si k-1
	lw $t4,0($sp)
	lw $t5,16($sp)
	add $t4,$t5,$t4       #rezultat(poz 0) = rezultat(poz 0) + rezultat(poz 16)
	sw $t4,16($sp)        #rescrierea rezultatului (t3) cu 4 casute in urma
	addi $t4,$0,0         #reinitializarea lui t3 cu 0 si rescrierea in stiva
	sw $t4,0($sp)
	addi $sp,$sp,16        #pop t3, ra, t1, t2, eliberarea stivei
	lw $ra,4($sp)
	jr $ra

return:
	lw $t4,0($sp)
	addi $t4,$t4,1         
	sw $t4,0($sp)          #rescrierea lui t3 in stiva cu t3 +1
	lw $ra,4($sp)          
	jr $ra