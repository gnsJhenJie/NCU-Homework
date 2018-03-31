#1st question
	.data
instring:	.asciiz	"Input:\n"
outstring:	.asciiz	"Output:\n"
star:	.asciiz "*"
blank:	.asciiz	" "
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
############################################################
	move $s0,$v1 
	addi $t0,$s0,-1
L2:					##first line
	la $a0,blank
	syscall
	addi $t0,$t0,-1
	bne $t0,$zero,L2
	la $a0,star
	syscall
	la $a0,next
	syscall

	addi $t9,$s0,-1
	addi $t7,$zero,-1
L3:					##arrow
	addi $t8,$s0,-2
	addi $t7,$t7,1
	sub $t8,$t8,$t7
	move $t6,$zero
LL31:
	beq $t8,$zero,LL31end
	la $a0,blank
	syscall
	addi $t8,$t8,-1
	bne $t8,$zero,LL31
LL31end:
	la $a0,star
	syscall
LL32:
	beq $t6,$t7,LL32end
	la $a0,blank
	syscall
	addi $t6,$t6,1
	bne $t6,$t7,LL32
LL32end:
	la $a0,star
	syscall
	move $t6,$zero
LL33:
	beq $t6,$t7,LL33end
	la $a0,blank
	syscall
	addi $t6,$t6,1
	bne $t6,$t7,LL33
LL33end:
	la $a0,star
	syscall
	la $a0,next
	syscall
												
	addi $t9,$t9,-1
	bne $t9,$zero,L3
	
	move $t9,$s0
L4:
	addi $t8,$s0,-1
LL4:
	la $a0,blank
	syscall
	addi $t8,$t8,-1
	bne $t8,$zero,LL4
LL4end:
	la $a0,star
	syscall
	la $a0,next
	syscall
	addi $t9,$t9,-1
	bne $t9,$zero,L4

	add $t9,$s0,$s0
	addi $t9,$t9,-1
L5:
	la $a0,star
	syscall
	addi $t9,$t9,-1
	bne $t9,$zero,L5
L5end:
	la $a0,next
	syscall
	
	addi $t9,$s0,-2
	move $t8,$zero
	
L6:
	beq $t9,$zero,L6end
	move $t7,$zero
	la $a0,star
	syscall
LL61:
	beq $t7,$t8,LL61end
	la $a0,blank
	syscall
	addi $t7,$t7,1
	bne $t7,$t8,LL61
LL61end:
	la $a0,star
	syscall
	add $t6,$t9,$t9
	addi $t6,$t6,-1
LL62:
	la $a0,blank
	syscall
	addi $t6,$t6,-1
	bne $t6,$zero,LL62
LL62end:
	la $a0,star
	syscall
	move $t7,$zero
LL63:
	beq $t7,$t8,LL63end
	la $a0,blank
	syscall
	addi $t7,$t7,1
	bne $t7,$t8,LL63
LL63end:
	la $a0,star
	syscall
	la $a0,next
	syscall
	addi $t9,$t9,-1
	addi $t8,$t8,1
	bne $t9,$zero,L6
L6end:
	
	
	
	
	
L7:
	addi $t9,$s0,-2
	la $a0,star
	syscall
LL7:
	beq $t9,$zero,LL7end	
	la $a0,blank
	syscall
	addi $t9,$t9,-1
	bne $t9,$zero,LL7
LL7end:
	la $a0,star
	syscall
	addi $t9,$s0,-2
LL77:
	beq $t9,$zero,L7end
	la $a0,blank
	syscall
	addi $t9,$t9,-1
	bne $t9,$zero,LL77
L7end:
	la $a0,star
	syscall
	la $a0,next
	syscall
	
	addi $t9,$s0,-2
	addi $t8,$t9,-1	
	move $t3,$zero
	addi $t3,$t3,1
L8:
	beq $t9,$zero,L8end
	move $t7,$zero
	la $a0,star
	syscall
LL81:
	beq $7,$t8,LL81end
	la $a0,blank
	syscall
	addi $t7,$t7,1
	bne $t7,$t8,LL81
LL81end:
	la $a0,star
	syscall
	add $t6,$t3,$t3
	addi $t6,$t6,-1
LL82:
	la $a0,blank
	syscall
	addi $t6,$t6,-1
	bne $t6,$zero,LL82
LL82end:
	la $a0,star
	syscall
	move $t7,$zero
LL83:
	beq $t7,$t8,LL83end
	la $a0,blank
	syscall
	addi $t7,$t7,1
	bne $t7,$t8,LL83
LL83end:
	la $a0,star
	syscall
	la $a0,next
	syscall
	addi $t9,$t9,-1
	addi $t8,$t8,-1
	addi $t3,$t3,1
	bne $t9,$zero,L8
L8end:
	
	
	
	
	
	
	add $t9,$s0,$s0
	addi $t9,$t9,-1
L9:
	la $a0,star
	syscall
	addi $t9,$t9,-1
	bne $t9,$zero,L9
L9end:
	la $a0,next
	syscall
		
		
############################################################	
	
	
	
################


################
	beq $zero,$zero,L1	#big loop
done:
	
