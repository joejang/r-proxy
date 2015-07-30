
.. default-role:: code

======================================================
        R-Proxy
======================================================

**Author**:*joejang@163.com*
**Source**:*pc4y.com*
**Date**:*07/24/2015*

*Abstract:A brief introduction to R-Proxy. R-Proxy is a keep-alive connection based reverse proxy solution, which provides remote clients with the ability to access local services by passing data through intermediate gateways or firewalls between the remote clients and the local services.*

Overview of Architecture
==========================


Flow Chart
==========================


Points
==========================


About The Project
==========================

Draft
==========================


Requirement
-----------

Before considering about the architecture, I had to think about the main points of this project:
        *Convenience* - Sync up local change to the remote. Use tools we can easily get on hand, Dropbox or xCloud for example.
        *Multi Format* - Convertion of Markdown and reStructuredText is available.
        AND, that's all, by now.


Overall Architecture
--------------------

.. image:: http://pc4y.com/homeres/building_websites_with_restructuredtext.png

Overall Architecture

Other Issues
============

Conversion from rst to html
---------------------------

I have tried tools like pandoc and rst2html, and both have some problems.

+------------+---------------------------------+-------------------------------------------+
| Tool       | Pros                            | Cons                                      |
+============+=================================+===========================================+
| pandoc     | Support multiple formats.       | Lack for enough default CSS templates.    |
+------------+---------------------------------+-------------------------------------------+
| rst2html   | Provide CSS templates.          | Unable to convert only body part of html. |
+------------+---------------------------------+-------------------------------------------+
| InstantRst | Instant result watching in Vim. | Inconvenient to invoke without Vim.       |
+------------+---------------------------------+-------------------------------------------+

To perform the instant coversion from rst to html, we need the help of the tool(s) mentioned above.

As we have compared the advantage and disadvantage of each tool for us, we may choose one or more tools that are most suitable for us to finish the auto-conversion job.

For this website, I used php scripts to call a rst_to_html.py to perform the conversion. 

And the rst_to_html.py is simply an encapsulation of some basic functions of Docutil and Pygments.

Conversion from markdown to html
--------------------------------

As I said that the website is going to support conversion from both reStructuredText and Markdown documents, here is the other conversion branch of Markdown using Michelf's `php-markdown <https://github.com/michelf/php-markdown>`_.

Cloud Syncing
-------------

There are many choices to support cloud syncing.

        *Dropbox, SugarSync, LiveSync...* - Multiplatform and easy-to-use.
        
        *rsync* - Command line, easy-to-use, flexible and peer-to-peer.

        *Pogoplug, xCloud* - Private cloud storage, data security, support for NAS.

        *BitTorrent Sync*

        *FTP*

Demo
====

With the steps above, this local-editing and remote-browsing website is built and it is quite convenient to use. 

The whole website is an "accomplished demo". All the html pages on this website you are reading now are converted from rst or md formated documents automatically.
