# Title: Exam Seating Plan

## Members:

1. Muhammad Rameez(06)
2. Mehtab Haider(10)

### Link:

[Exam Seating Plan Repository](https://github.com/PatheticUser/Exam-Seating-Plan)

## Integrated Features:

- Authentication & Authorization(Login)
- Registration
- Backup
- Seating Plan Generation
- Templates For Generation
- Display Plan
- Edit Plan
- Input Validation
- Conflict Resolution During Registration
- Organized CLI Interface
- Save Plan To File

## Abstract:

The Exam Seating Plan System is a command-line program developed in C++ designed to generate exam seating plans based on the number of classes provided. It merges different classes and their student strengths into single halls, accommodating various class sizes. The system offers different seating plan templates including random, sequential, and mixed random. The mixed random plan organizes students evenly, followed by odd students, and then random placement, providing a balanced seating arrangement.

Key features include user registration and login functionalities, dependent on file management. Teachers, as administrators, require a specific key ("KEY") for registration to access administrative controls. Students can register and login to view the most recent exam plans published by administrators. The system also allows for backup of exam plans to new files, enabling easy retrieval and preservation of seating arrangements. Additionally, teachers have the ability to edit seating plans post-generation, facilitating modifications such as seat swaps and assignments.

# Note:

In developing the Exam Seating Plan System, I made use of four libraries: iostream, ctime, fstream, and limits. While iostream and fstream were introduced and taught to us by Sir Umar, while ctime and limits were not explicitly covered in our coursework.

I opted to use ctime to access system time for generating random seating plans, a crucial aspect of the project. Additionally, I utilized the limits library to ensure robust input validation and exception handling.

I acknowledge that the use of libraries not explicitly taught may raise concerns, but I made a deliberate effort to thoroughly understand these libraries and few others on my own while exploring C++ before this project came up.

In the context of this project, where the goal is to create a functional and comprehensive exam seating plan system, leveraging these libraries was necessary for achieving the required functionality and quality standards. As in future if our program isn't able to handle exception & input validation. It will be considered good.Also if it is not doing what it is meant to be then it will not be called a successful program.

I kindly request that my use of additional libraries not be penalized, as they were essential for the successful implementation of the project's requirements. Thank you for considering my request and evaluating the program accordingly.
