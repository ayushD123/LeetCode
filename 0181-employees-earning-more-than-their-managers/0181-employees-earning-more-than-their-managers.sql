select b.name as Employee from employee a join employee b on a.id=b.managerid and a.salary<b.salary;