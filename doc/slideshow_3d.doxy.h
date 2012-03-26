/**
 * @~english
 * @taomoduledescription{SlideShow3D, Photo Slide Show in 3D}
 *
 * Shows a collection of pictures on a rotating 3D sphere.
 *
 * With this module, you can create a nice animation showing pictures
 * from a disk folder.
 * For example, let's suppose you have 24 JPEG photos in the @c photos
 * folder. The following example
 *(<a href="examples/slideshow_3d.ddd">slideshow_3d.ddd</a>) will load
 * all the photos and show them on a slowly rotating sphere:
 * @include slideshow_3d.ddd
 *
 * @image html slideshow_3d.png "Output from slideshow_3d.ddd"
 *
 * Note that there is a template document that further illustrates this
 * module.
 *
 * @endtaomoduledescription{SlideShow3D}
 * @~french
 * @taomoduledescription{SlideShow3D, Carrousel de photos en 3D}
 *
 * Affiche un ensemble d'images sur une sphère qui tourne.
 *
 * Ce module vous permet d'afficher une animation en 3D à partir de photos
 * qui se trouvent dans un répertoire.
 * Par exemple, supposons que vous ayez 24 photos JPEG dans le dossier
 * @c photos. Le code qui suit montre toutes les photos sur une sphère qui
 * tourne lentement.
 * @include slideshow_3d.ddd
 *
 * @image html slideshow_3d.png "Carrousel de photos"
 *
 * Il existe un modèle de documents qui illustre ce module.
 *
 * @endtaomoduledescription{SlideShow3D}
 *
 * @~
 * @{
 */



/**
 * @~english
 * The index of the next image to be added to the slide show.
 *
 * Just make sure you reset this variable to 0 before calling
 * @ref show_image in sequence (see the above example).
 *
 * @~french
 * L'index de la prochaine image à ajouter au carrousel.
 *
 * Prenez garde à remettre cette variable à zéro avant d'appeler
 * @ref show_image sur une série de fichiers (voir l'exemple plus haut).
 */
integer image_index = 0;

/**
 * @~english
 * Whether to show back or front images.
 *
 * When this variable is 1.0, @ref show_image renders only the images on
 * the front of the sphere. When it is -1.0, @ref show_image renders
 * the images on the back of the sphere.
 *
 * @~french
 * Permet d'afficher les images qui sont devant ou derrière.
 *
 * Lorsque cette variable vaut 1.0, @ref show_image affiche seulement les
 * images qui forment l'avant de la sphère. Lorsqu'elle vaut -1.0,
 * @ref show_image affiche seulement les images à l'arrière de la sphère.
 */
real show_front = 1.0;

/**
 * @~english
 * The number of images locations on the surface of the sphere.
 * No more than @ref SHOWN images will be displayed simultaneously.
 *
 * @~french
 * Le nombre d'emplacements sur la sphère pour montrer des images.
 * C'est le nombre maximum d'images affichées simultanément.
 */
integer SHOWN = 36;

/**
 * @~english
 * The width of each image.
 *
 * Images are scaled proportionally to fit the specified width in pixels.
 *
 * @~french
 * La largeur de chaque image.
 * Les images sont redimensionnées si nécessaire (en respectant leur rapport
 * largeur/hauteur).
 */
integer SIZE = 400;

/**
 * @~english
 * The rotation speed of the image sphere.
 *
 * The sphere rotates around the y axis at a speed of one turn every @ref SHOWN
 * seconds by default. To put it differently, a new image faces the viewer each
 * second.
 *
 * You may adjust the speed by changing @ref SPEED, which
 * acts as a multiplication factor.
 *
 * @~french
 * La vitesse de rotation de la sphère qui porte les images.
 *
 * La sphère tourne selon l'axe @c y à une vitesse de un tour toutes les
 * @ref SHOWN secondes par défaut. Autrement dit, une nouvelle image fait face
 * à l'utilisateur chaque seconde.
 *
 * Vous pouvez ajuster cette vitesse en changeant @ref SPEED, qui est un
 * facteur multiplicatif.
 */
real SPEED = 1.0;

/**
 * @~english
 * A value added to page_time when computing the animation.
 * Allows to start with several images already visible.
 * @~french
 * Une valeur ajoutée à page_time lors du calcul de l'animation.
 * Permet de démarrer avec plusieurs imagess déjà visibles.
 */
real TIME_OFFSET = 0.0;

/**
 * @~english
 * The radius of the sphere is in pixels.
 * @~french
 * Le rayon de la sphère en pixels.
 */
integer RADIUS = 1200;

/**
 * @~english
 * The total number of images.
 *
 * If @ref MAX is larger than the image collection, the slideshow will show a
 * gap as it rotates. If it is smaller, some images will overlap.
 *
 * @~french
 * Le nombre total d'images.
 * Si @ref MAX est plus grand que le nombre d'images passés à @ref show_image,
 * le carrousel aura un "trou". Au contraire, si @ref MAX est plus grand,
 * certaines images vont se chevaucher.
 */
integer MAX = 270;

/**
 * @~english
 * Adds an image to the collection and draw it if required.
 *
 * To create a slideshow, you call @ref show_image repeatedly for all the
 * files to be displayed. The @c with keyword and the @ref files builtin
 * are especially useful here:
 @code
show_image with files "*.jpg"
 @endcode
 *
 * Depending on the current parameter values, and the current page time,
 * @ref show_image will draw the image at the suitable location.
 *
 * @~french
 * Ajoute une image au carrousel et l'affiche si nécessaire.
 *
 * Pour créer un carrousel, vous appelez @ref show_image de manière répétée
 * pour chaque image que vous désirez afficher. Le mot-clé @c with et
 * la primitive @ref files sont particulièrement utiles ici :
 @code
show_image with files "*.jpg"
 @endcode
 *
 * En fonction des paramètres définis dans ce module, et en fonction
 * également de la valeur de @ref page_time, l'image sera affichée
 * au bon endroit.
 */
show_image(filename:text);

/**
 * @}
 */
