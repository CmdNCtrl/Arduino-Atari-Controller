# WordPress article source

`post.html` contains the editable Gutenberg block markup for [Connecting an Atari Controller to a Computer](https://druding.com/2026/09/27/connecting-an-atari-controller-to-a-computer/), WordPress post 725 on druding.com. This is the post body, not the site theme or template. Images remain referenced by their existing URLs.

`post.json` records the source post metadata and export time. Git history tracks revisions.

## Update workflow

1. Whenever an update to this article is requested, fetch post 725 through the WordPress connector with `context: edit` before editing. Treat the live post as the current source, since it may have been edited in WordPress.
2. Refresh these two files and commit any incoming changes as a separate baseline before applying the requested edits. Do not overwrite uncommitted local work; preserve it or reconcile it first.
3. Make the authorized changes and verify WordPress has not changed since the read. Prefer section-level edits for localized changes.
4. After saving, fetch the post again, refresh these files with the actual saved content, and commit the result with a descriptive message. Check WordPress content warnings.
5. Stage only the article files involved. Do not include unrelated working-tree changes. Push when requested.

To restore an earlier version, review the Git diff first and use the chosen `post.html` as the article body in WordPress's code editor or connector.
