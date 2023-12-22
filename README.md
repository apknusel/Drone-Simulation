# Drone Simulation
## Team-001-06
<p>Alex Knusel - knuse001<br>
Hady Kotifani - kotif004</p>

## Video Demonstration
https://youtu.be/eqPaqTn9HzA

## Project Description
<p>This project is a drone simulation where drones are used to deliver packages to robots. The user can determine the location of a package and the location of a robot for the drone to deliver the package to. There are two types of drones in the simulation; a battery drone and a charging drone. The battery drone has a battery with a limited lifetime and is in charge of delivering packages. The charging drone also has a battery, but is in charge of charging drones when they die to allow the drones to continue delivering drones. This design is similar to the way Lime, Spin, and Veo charge their scooters around Minneapolis. They use vans to drive out to the location of the scooters when they die, charge the scooters, and then put them back on the street where they were left. The simulation also has a helicopter that flies in a straight line between random locations and a parrot that flies in circles :smiley:.</p>

## Running the Simulation

### Manually
1. Clone the repository
```
git clone https://github.umn.edu/umn-csci-3081-f23/team-001-06-hw4.git
```
2. Navigate into the repository
```
cd team-001-06-hw4
```
3. Call run in the Makefile
```
make run
```
4. Launched at [http://localhost:8081/](http://localhost:8081/)

### Docker ([Repository](https://hub.docker.com/repository/docker/alexknusel/drone_sim/general))
1. Install [docker](https://docs.docker.com/engine/install/)
2. Run in terminal
```
docker run --rm -p 8081:8081 alexknusel/drone_sim
```
3. Launched at [http://localhost:8081/](http://localhost:8081)

## Features

### Base Features

#### Package Delivery
> The ability to select a location for a package to be created and then the robot that it should be deliver to for the destination.

#### Drone Movement Strategies
> The drone has multiple movement strategies such as Beeline, A-star, DFS, BFS, and Dijkstra's Algorithm to navigate to packages and destinations.

#### Person Walking
> There is a human that runs around the simulation and the user is able to create more humans from the schedule page.

#### Helicopter Flying
> There is a helicopter that randomly flys around the simulation for added immersion.

### New Features

#### Battery Drone
> The Battery Drone is responsible for flying to packages that are scheduled and delivering them to robots. This is interesting because it brings up the problem of how to charge the drones. Do you wait until the drones are dead? Have the drone fly to a Recharge Station at 50%? Have another drone charge the drone? This new feature adds to the exisiting work by being a decorator for the Drone which was already in the simulation. We chose to use the **decorator design pattern** because a Battery Drone still delivers packages and uses other functionalities provided in the Drone class. We also use the **factory design pattern** for creating the drones to allow for multiple drones and easy expansion. This feature is automatically incorporated in the simulation upon running the simulation.

#### Charging Drone
> The Charging Drone is responsible for charging Battery Drones that are flying around and delivering packages. This is interesting because it solves the problem of what to do when a Battery Drones dies and mimics the way some scooters around Minneapolis are charged. This adds to the existing work by further extending drone functionality and extending the Battery Drone that we implemented. We chose to implement the **decorator desgin pattern** because the funcitonality of the Charging Drone is very similar to the way the drone works. We also used the **factory design pattern** with this feature to allow for easier expansion in the future. This feature is automatically incorporated in the simulation upon running the simulation.

#### Recharge Station
> The Recharge Station charges the Charging Drone when it flies over to it's location. This is interesting because in the simulation there needs to be a way to charge the Charging Drones that are charging the Battery Drones. The recharge station is in approximately the center of the simulation which allows it to act as a good hub for charging any drone. We use the **factory design pattern** for creating the Recharge Station because it allows for scalability and having mutliple recharge stations in the future even though we only have one in our simulation. This feature is automatically incorporated in the simulation upon running the simulation.

#### Parrot
> The parrot flies in circles around the simulation at varying heights. This is from our addition in Lab 10 and we thought it would be worth including. The Parrot is interesting because it uses a new movement strategy called Circle Strategy where the parrot flies in circles around a randomly selected point. This adds to the existing works by implementing the IStrategy class. This isn't super interesting as it is just a parrot flying around the simulation, but it does show how easy it is to extend the project and incorporate new models. This feature uses the **factory design pattern** to allow for easier expansion. This feature is automatically incorporated in the simulation upon running the simulation.

## Sprint Retrospective

### What did we do well?
- Communicated very well. Everyone was kept up to date on the current state of the project
- Responded to eachother in a timely manner
- Efficiently worked together while pair programming in lab
- Stuck to our plan and made adjustments as needed

### What have we learned?
- How to communicate effectively as a team, giving frequent and high quality updates
- Learned how to make a high-quality README for a project :smiley:
- How to understand a complex system well enough to add new, interesting features

### What should we do differently?
- Spend more time in the planning phase
- Should have made high level UML (just class associations, not functions) before starting programming

### Future Improvements
- Better pathing for Charging Drone to determine if it should fly back to the battery station or to another drone to charge
- Ability for the user to add Charging Drones and Battery Drones

## UML Diagram of New Feature
![Homework 4](https://media.github.umn.edu/user/22922/files/c63ebc41-0c47-42f3-b825-6eee5a08d563)
