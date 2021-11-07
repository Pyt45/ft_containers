function sortLibrary() {
    library.sort((obj1, obj2) => (obj1.title > obj2.title) ? 1 : (obj1.title < obj2.title) ? -1 : 0)
}

// tail starts here
var library = [
    {
        author: 'Bill Gates',
        title: 'The Road Ahead',
        libraryID: 1254
    },
    {
        author: 'Steve Jobs',
        title: 'Walter Isaacson',
        libraryID: 4264
    },
    {
        author: 'Suzanne Collins',
        title: 'Mockingjay: The Final Book of The Hunger Games',
        libraryID: 3245
    }
]


sortLibrary()

console.log(library)