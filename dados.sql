create table usuarios
(
cpf integer,
nome varchar(50),
sobrenome varchar(50),
cargo varchar(50),
id_curso integer
)

create table cursos
(
id integer,
nome_curso varchar(50),
professor varchar(50),
categoria_curso varchar(50)
)



insert into usuarios (cpf, nome, sobrenome, cargo, id_curso)
values ('09876543210', 'Giacomo', 'Salsano', 'Aluno', '1');

insert into usuarios (cpf, nome, sobrenome, cargo, id_curso)
values ('11122233300', 'Domitila', 'Salsano', 'Aluno', '2');

insert into usuarios (cpf, nome, sobrenome, cargo, id_curso)
values ('22200022200', 'Ciclano', 'Fulano', 'Aluno', '2');



insert into usuarios (cpf, nome, sobrenome, cargo, id_curso)
values ('12345678900', 'Lucas', 'Souza', 'Professor', '1');

insert into usuarios (cpf, nome, sobrenome, cargo, id_curso)
values ('00099988811', 'Beltrano', 'Fulano', 'Professor', '2');



insert into cursos (id, nome_curso, professor, categoria_curso)
values ('1', 'TI do Zero', 'Lucas Souza', 'TI');

insert into cursos (id, nome_curso, professor, categoria_curso)
values ('2', 'Marketing do Zero', 'Beltrano Fulano', 'Marketing');

select * from usuarios;

select * from cursos;



select * from usuarios
where cpf = '09876543210';




select * from usuarios, cursos
where usuarios.id_curso = cursos.id
and usuarios.id_curso = '1';



select * from usuarios, cursos
where usuarios.id_curso = cursos.id
and cursos.categoria_curso = 'Marketing';



select * from usuarios
where nome = 'Beltrano';



delete from usuarios
where cpf = '00099988811';



delete from usuarios
where cpf = '00099988811';



update usuarios
set id_curso='1'
where cpf='22200022200';
