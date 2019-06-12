use db_project;

create table Department (
	id int not null auto_increment,
    name varchar(20) not null,
    class varchar(10) not null,
    
    primary key (id),
    constraint UC_Department unique (name, class)
);

create table Student (
	id int not null auto_increment,
    semester varchar(10) not null,
    student_number varchar(10) not null,
	name varchar(20) not null,
    Department_id int not null,
    grade int,
    status varchar(10) not null,
    
    primary key (id),
    foreign key (Department_id) references Department(id),
    constraint UC_Student unique (semester, student_number)
);

create table Room (
	id int not null auto_increment,
    name varchar(20) not null,
    
    primary key (id),
    constraint UC_Room unique (name)
);

create table Teacher (
	id int not null auto_increment,
    name varchar(20) not null,
    
    primary key (id)
);

create table CourseTime (
	id int not null auto_increment,
    timeslot varchar(10) not null,
    
    primary key (id),
    constraint UC_CourseTime unique (timeslot)
);

create table Course (
	id int not null auto_increment,
    semester varchar(10) not null,
    course_number varchar(10) not null,
    name varchar(20) not null,
    type varchar(10) not null,
    credit int not null,
    status varchar(10) not null,
    Teacher_id int,
    Room_id int,
    
    primary key (id),
    foreign key (Teacher_id) references Teacher(id),
    foreign key (Room_id) references Room(id),
    constraint UC_Course unique (semester, course_number)
);

create table WhenCourse (
	id int not null auto_increment,
    Course_id int not null,
    CourseTime_id int not null,
    
    primary key (id),
    foreign key (Course_id) references Course(id),
    foreign key (CourseTime_id) references CourseTime(id),
    constraint UC_WhenCourse unique (Course_id, CourseTime_id)
);

#delimiter //
#  
#create function CheckSemester(s_id int, c_id int)
#	returns int deterministic
#    
#    begin
#		return case when (select semester from Student where id = s_id limit 1) = (select semester from Course where id = c_id limit 1) then 1 else 0 end;
#    end //
#    
#delimiter ;

create table TakeCourse (
	id int not null auto_increment,
    Student_id int not null,
    Course_id int not null,
    score float,
    feedback_rank float,
    feedback_memo text,
    
    primary key (id),
    foreign key (Student_id) references Student(id),
    foreign key (Course_id) references Course(id),
    constraint UC_TakeCourse unique (Student_id, Course_id)
);

#show function status;
show tables;