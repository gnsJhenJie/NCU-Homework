use db_project;

# 1. 計算機概論，因故上課地點要由L102修改到K210大教室，該怎麼做？
select name from Room where id in (select Room_id from Course where semester = '1072' and course_number = 'CE1004');
update Course set Room_id = (select id from Room where name = 'L102') where semester = '1072' and course_number = 'CE1004';




# 2. 如何得知每堂課的修課名單列表（點名表）？
select Student.student_number as '學號', Student.name as '名字' from Student 
where Student.id in (
	select TakeCourse.Student_id from TakeCourse join Course on TakeCourse.Course_id = Course.id
    where Course.semester = '1072' and Course.course_number = 'CE1004'
);




# 3. 想知道1072學期哪一門課修課狀況最熱烈，要怎麼做？
select Course.course_number as '課號', Course.name as '課名', count(*) as '總人數' from TakeCourse join Course on TakeCourse.Course_id = Course.id
where Course.semester = '1072'
group by Course.semester, Course.course_number
order by count(*) desc;




# 4. 想知道1072學期各科總成績不及格（低於60分）的人，要怎麼做？
select Course.semester as '學期', Course.course_number as '課號', Course.name as '課名', Student.student_number as '學號', Student.name as '名字', TakeCourse.score as '總成績'
from TakeCourse join Course on TakeCourse.Course_id = Course.id
	 join Student on TakeCourse.Student_id = Student.id
where TakeCourse.score < 60;




# 5. 如何得知1072學期，最受學生歡迎的前十門課有哪些，要怎麼做？
select Course.course_number as '課號', Course.name as '課名', Teacher.name as '教授', avg(TakeCourse.feedback_rank) as '教學評量'
from TakeCourse join Course on TakeCourse.Course_id = Course.id
	 join Teacher on Course.Teacher_id = Teacher.id
where Course.semester = '1072'
group by Course.semester, Course.course_number
order by avg(TakeCourse.feedback_rank) desc
limit 10;











