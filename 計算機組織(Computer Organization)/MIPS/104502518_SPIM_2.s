#2nd question
	.data
instring:	.asciiz	"Input:\n"
outstring:	.asciiz	"Output:\n"
next:	.asciiz "\n"
	.text
main:
	
L1:
	li $v0,4
	la $a0,instring
	syscall
	li $v0,5
	syscall			#input number in $v0
	beq $v0,$zero,done	#the end input
	move $v1,$v0
	li $v0,4
	la $a0,outstring
	syscall
	move $s0,$v1
############################################################
	move $t9,$s0
	addi $t1,$t1,1
	addi $t2,$t2,2
	addi $sp,$sp,-4
	sw $t9,0($sp)
	jal functionstair
	beq $zero,$zero,countover
functionstair:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	beq $t9,$t2,plus2
	beq $t9,$t1,plus1
	beq $zero,$zero,other
plus2:
	addi $t0,$t0,2
	beq $zero,$zero,functionover
plus1:
	addi $t0,$t0,1
	beq $zero,$zero,functionover
other:
	addi $sp,$sp,-4
	sw $t9,0($sp)
	addi $t9,$t9,-1
	jal functionstair
	addi $sp,$sp,-4
	sw $t9,0($sp)
	addi $t9,$t9,-2
	jal functionstair
functionover:
	lw $ra,0($sp)
	addi $sp,$sp,4
	lw $t9,0($sp)
	addi $sp,$sp,4
	jr $ra
	
		
				
countover:
	li $v0,1
	la $a0,($t0)
	syscall
	li $v0,4
	la $a0,next
	syscall
	move $t1,$zero
	move $t2,$zero
	move $t0,$zero
############################################################	
	

	beq $zero,$zero,L1	#big loop
done:
	
