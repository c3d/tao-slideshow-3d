/**
 * @~english
 * @taomoduledescription{SlideShow3D, 3D Slide Show}
 *
 * Defines some 3D slide shows.
 *
 * With this module, you can create nice animations with your various contents.
 * For example, the following code creates a simple slide show of 3D shapes.
 * @include slideshow_3d.ddd
 *
 * @image html slideshow_3d.png "Output from slideshow_3d.ddd"
 *
 * Note that there is also a template document that further illustrates this
 * module.
 *
 * @endtaomoduledescription{SlideShow3D}
 * @~french
 * @taomoduledescription{SlideShow3D, Diaporama 3D}
 *
 * Définit différents diaporamas 3D.
 *
 * Ce module vous permet d'intégrer des animations en 3D à vos présentations
 * pour afficher vos contenus les plus divers.
 * Par exemple, Le code qui suit montre un diaporama simple comprenant
 * des formes géométriques 3D.
 * @include slideshow_3d.ddd
 *
 * @image html slideshow_3d.png "Diaporama de formes géométriques"
 *
 * Il existe également un modèle de documents qui illustre ce module.
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
 * L'index de la prochaine image à  ajouter au carrousel.
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
 * La sphère tourne selon l'axe @c y à  une vitesse de un tour toutes les
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
 * Permet de démarrer avec plusieurs imagess déjà  visibles.
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
 * @~english
 * Create a slider effect.\n
 *
 * Define a basic slider effect with @n items defined by the function @p f.
 * So, it is very important for each item, the correct behavior of this function @p f.
 * For instance, the following example create a slide show with four pictures.
@code
picture 1 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_1.jpg"
picture 2 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_2.jpg"
picture 3 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_3.jpg"
picture 4 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_4.jpg"
slider 4, picture
@endcode
 *
 * The alternative code below is also possible :
@code
picture N:integer ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @~french
 * Créé un effet de diaporama.
 *
 * Définit un diaporama basique avec @n éléments définit par la fonction @p f.
 * Il est donc important de définir pour chacun des éléments du diaporama,
 * le comportement correct de cette fonction @p f.
 * Par exemple, le code suivant créé un diaporama comprenant quatres photographies.
 *
 @code
picture 1 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_1.jpg"
picture 2 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_2.jpg"
picture 3 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_3.jpg"
picture 4 ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_4.jpg"
slider 4, picture
 @endcode
 *
 * Le code ci-dessous est également possible :
@code
picture N:integer ->
    color "white"
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 */
slider(n:integer, f:tree);


/**
 * @~english
 * Sets offsets of the slider.\n
 *
 * Defines offsets between each item of the slider defined by @ref slider.
 *
 * @param x horizontal offset. Default value is 0.0
 * @param y vertical offset. Default value is 0.0
 * @param z depth offset. Default value is 0.0
 *
 * For instance, to define an horizontal slider :
@code
slider_offset 300, 0, 0
@endcode
 *
 * @~french
 * Spécifie les paramètres de décalage du diaporama.
 *
 * Définit les décalages entre chaque élément du diaporama créé par @ref slider.

 * @param x décalage horizontal. La valeur par défaut est 0.0.
 * @param y décalage vertical. La valeur par défaut est 0.0.
 * @param z décalage en pronfondeur. La valeur par défaut est 0.0.
 *
 * Par exemple, pour réaliser un diaporama horizontal :
@code
slider_offset 300, 0, 0
@endcode
 */
slider_offset(x:real, y:real, z:real);


/**
 * @~english
 * Sets size of a slider.\n
 *
 * Specifies the size of the slider created by @ref slider.
 *
 * @param w Width of the slider. Default value is @ref window_width.
 * @param h Height of the slider. Default value is @ref window_height.
 * @param d Depth of the slider. Default value is @ref z_near.
 *
 *
 * @~french
 * Modifie la taille du diaporama.\n
 *
 * Spécifie la taille du diaporama créer par @ref slider.
 *
 * @param w Largeur du diaporama. La valeur par défaut est @ref window_width.
 * @param h Hauteur du diaporama. La valeur par défaut est @ref window_height.
 * @param d Profondeur du diaporama. La valeur par défaut est @ref z_near.
 *
 */
slider_size(w:real, h:real, d:real);


/**
 * @~english
 * Moves Automatically the slider.\n
 *
 * This function allows to move automatically the slider at the speed @p s.
 * For instance,
@code
slider_auto_move page_time * 0.1
@endcode
 *
 * @note if the movement of the slider is set to automatic,
 * then @ref slider_next and @ref slider_previous are disable.
 *
 * @~french
 * Bouge automatiquement le diaporama.
 *
 * Cette fonction permet de bouger automatiquement le diaporama à la vitesse @p s.
 * Par exemple,
@code
slider_auto_move page_time * 0.1
@endcode
 *
 * @note Si le mouvement du diaporama est mis en automatique,
 * alors les fonctions @ref slider_next et @ref slider_previous sont désactivés.
 */
slider_auto_move(s:real);


/**
 * @~english
 * Specifies velocity of the slider.\n
 *
 * This function allows to set the transition velocity between each item of the slider.
 * This velocity is a real comprised between 0 and 1.
 *
 * @param v Velocity of the slider transitions. Default value is 0.05.
 *
 * For instance,
@code
slider_velocity 0.3
@endcode
 *
 * @~french
 * Spécifie la vitesse de transition du diaporama.
 *
 * Cette fonction permet de modifier la vitesse de transition entre chaque élément du diaporama.
 * Cette vitesse est un réel compris entre 0 et 1.
 *
 * @param v Vitesse de transition du diaporama. La valeur par défaut est 0.05.
 *
 * Par exemple,
@code
slider_velocity 0.3
@endcode
 *
 */
slider_auto_move(s:real);


/**
 * @~english
 * Go to the next item of the slider.\n
 *
 * This function allows to move forward the slideshow defined by @ref slider.
 * A simple use case is :
@code
// Move forward the slider with Left key
key "Left" -> slider_next
@endcode
 *
 * @~french
 * Avance jusqu'au prochain élément du diaporama.
 *
 * Cette fonction permet d'avancer d'un élément le diaporama définit par @ref slider.
 * Un cas simple d'utilisation est :
@code
// Avance le diaporama avec la flêche gauche
key "Left" -> slider_next
@endcode
 */
slider_next();


/**
 * @~english
 * Go to the previous item of the slider.\n
 *
 * This function allows to move backward the slideshow defined by @ref slider.
 * A simple use case is :
@code
// Move backward the slider with Right key
key "Right" -> slider_previous
@endcode
 *
 * @~french
 * Recule jusqu'à l'élément précédent du diaporama.
 *
 * Cette fonction permet de reculer d'un élément le diaporama définit par @ref slider.
 * Un cas simple d'utilisation est :
@code
// Recule le diaporama avec la flêche droite
key "Right" -> slider_previous
@endcode
 */
slider_previous();

/**
 * @~english
 * Move slider according to x-position of the mouse.\n
 *
 * This function allows to move a slideshow defined by @ref slider thanks to a mouse move along the x-axis.
 *
 * @param s Sensiblity of the mouse move.
 *
 * @~french
 * Déplace le diaporama suivant la position en abscisse de la souris.
 *
 * Cette fonction permet de déplacer un diaporama définit par @ref slider à l'aide d'un déplacement de la souris
 * suivant l'axe x.
 *
 * @param s Sensiblité de la souris.
 */
slider_mouse_x(s:real);


/**
 * @~english
 * Move slider according to y-position of the mouse.\n
 *
 * This function allows to move a slideshow defined by @ref slider thanks to a mouse move along the y-axis.
 *
 * @param s Sensiblity of the mouse move.
 *
 * @~french
 * Déplace le diaporama suivant la position en ordonnée de la souris.
 *
 * Cette fonction permet de déplacer un diaporama définit par @ref slider à l'aide d'un déplacement de la souris
 * suivant l'axe y.
 *
 * @param s Sensiblité de la souris.
 */
slider_mouse_x(s:real);


/**
 * @~english
 * Compute value to be used for horizontal fade-in effects of a slider.
 *
 * Return for an item @p N, a value that fades approximately from 0.0 to 1.0, computed according to its position
 * relative to the center.
 * The parameter @p Sx is the fade-in velocity along x-axis.
 *
 * For instance, to add an horizontal fade-in effect to the example of @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_x N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_x N @endcode is a shortcut to @code slider_fade_x N, 1.1 @endcode
 *
 * @~french
 * Calcule une valeur utilisée pour des effets d'apparitions horizontales d'un diaporama.\n
 *
 * Renvoie pour un élément @p N, une valeur comprise entre 0 et 1, calculée suivant sa position relative
 * par rapport au centre.
 * Le paramètre @p Sx correspond à la vitesse d'apparition suivant l'axe x.
 *
 * Par exemple, pour rajouter un effet d'apparition horizontale à l'exemple de @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_x N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_x N @endcode est un raccourci à @code slider_fade_x N, 1.1 @endcode
 */
real slider_fade_x(N:integer, Sx:real);


/**
 * @~english
 * Compute value to be used for vertical fade-in effects of a slider.
 *
 * Return for an item @p N, a value that fades approximately from 0.0 to 1.0, computed according to its position
 * relative to the center.
 * The parameter @p Sy is the fade-in velocity along y-axis.
 *
 * For instance, to add a vertical fade-in effect to the example of @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_y N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_y N @endcode is a shortcut to @code slider_fade_y N, 1.1 @endcode
 *
 * @~french
 * Calcule une valeur utilisée pour des effets d'apparitions verticales d'un diaporama.\n
 *
 * Renvoie pour un élément @p N, une valeur comprise entre 0 et 1, calculée suivant sa position relative
 * par rapport au centre.
 * Le paramètre @p Sy correspond à la vitesse d'apparition suivant l'axe y.
 *
 * Par exemple, pour rajouter un effet d'apparition verticale à l'exemple de @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_y N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_y N @endcode est un raccourci à @code slider_fade_y N, 1.1 @endcode
 */
real slider_fade_y(N:integer, Sy:real);


/**
 * @~english
 * Compute value to be used for depth fade-in effects of a slider.
 *
 * Return for an item @p N, a value that fades approximately from 0.0 to 1.0, computed according to its position
 * relative to the center.
 * The parameter @p Sz is the fade-in velocity along the z-axis.
 *
 * For instance, to add a depth fade-in effect to the example of @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_z N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_z N @endcode is a shortcut to @code slider_fade_z N, 1.1 @endcode
 *
 * @~french
 * Calcule une valeur utilisée pour des effets d'apparitions en profondeur d'un diaporama.\n
 *
 * Renvoie pour un élément @p N, une valeur comprise entre 0 et 1, calculée suivant sa position relative
 * par rapport au centre.
 * Le paramètre @p Sz correspond à la vitesse d'apparition suivant l'axe z.
 *
 * Par exemple, pour rajouter un effet d'apparition en profondeur à l'exemple de @ref slider :
@code
picture N:integer ->
    alpha := slider_fade_z N, 1.1
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade_z N @endcode est un raccourci à @code slider_fade_z N, 1.1 @endcode
 */
real slider_fade_z(N:integer, S:real);


/**
 * @~english
 * Compute value to be used for fade-in effects of a slider.
 *
 * Return for an item @p N, a value that fades approximately from 0.0 to 1.0, computed according to its position
 * relative to the center.
 * The parameters @p Sx,@p Sy,@p Sz are respectively the fade-in velocity along the x-axis, y-axis, and z-axis.
 *
 * For instance, to add an original fade-in effect to the example of @p slider :
@code
picture N:integer ->
    alpha := slider_fade N, 1.1, 3.0, 2.0
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade N @endcode is a shortcut to @code slider_fade N, 1.1, 1.1, 1.1 @endcode
 *
 * @~french
 * Calcule une valeur utilisée pour réaliser des effets d'apparitions dans un diaporama.\n
 *
 * Renvoie pour un élément @p N, une valeur comprise entre 0 et 1, calculée suivant sa position relative
 * par rapport au centre.
 * Les paramètres @p Sx,@p Sy,@p Sz correspondent respectivement à la vitesse d'apparition suivant les axes x, y et z.
 *
 * Par exemple, pour rajouter un effet d'apparition originale à l'exemple de @p slider :
@code
picture N:integer ->
    alpha := slider_fade N, 1.1, 3.0, 2.0
    color "white", alpha
    image_px 0, 0, 500, 500, "your_picture_" & text N & ".jpg"
slider 4, picture
@endcode
 *
 * @note @code slider_fade N @endcode est un raccourci à @code slider_fade N, 1.1, 1.1, 1.1 @endcode
 */
real slider_fade(N:integer, Sx:real, Sy:real, Sz:real);


/**
 * @~english
 * The current item of the slider (i.e central item).
 *
 * @~french
 * L'élément courant du diaporama (i.e l'élément central).
 */
integer slider_front_item;


/**
 * @}
 */
